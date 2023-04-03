#ifndef GAME_HPP
#define GAME_HPP

#include "game.hpp"
#include "card.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <random>


using namespace std;
using namespace ariel;

Game::Game(Player p1, Player p2) : p1(p1), p2(p2),turns(),draws(0) {
    vector<card> deck;
    string suitTemp;
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 5; j++) {
            if (j == 1) suitTemp = "Hearts";
            else if (j == 2) suitTemp = "Diamonds";
            else if (j == 3) suitTemp = "Clubs";
            else suitTemp = "Spades";

            card newCard(i, suitTemp);
            deck.push_back(newCard);
        }
    }

    // Shuffle the deck
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    // Divides the deck between the players
    for (int i = 0; i < deck.size(); i++)
        if (i % 2 == 0)
            p1.stack.push_back(deck[i]);
        else   
            p2.stack.push_back(deck[i]);

}


void Game::playTurn() {


if (p1.stack.size() == 0 || p2.stack.size() == 0) {
        cout << "The game is over" << endl;
        return;
    }

    card p1Card = p1.stack[0];
    card p2Card = p2.stack[0];
    p1.stack.erase(p1.stack.begin());
    p2.stack.erase(p2.stack.begin());
    int count = 2;

    while (p1Card.compare(p2Card) == 0) {
        draws++;
        turns.push_back(p1.name + " played " + p1Card.toString() + ", " + p2.name + " played " + p2Card.toString() + ". Draw.");
        if (p1.stack.size() == 0 || p2.stack.size() == 0) {
            cout << "The game is over with a draw on the last turn" << endl;
            return;
        }
        //put the card upside downs
        p1Card = p1.stack[0];
        p2Card = p2.stack[0];
        p1.stack.erase(p1.stack.begin());
        p2.stack.erase(p2.stack.begin());

        p1Card = p1.stack[0];
        p2Card = p2.stack[0];
        p1.stack.erase(p1.stack.begin());
        p2.stack.erase(p2.stack.begin());
        count += 4;
    }

    if (p1Card.compare(p2Card) == 1) {
        p1.cardsWin += count;
        turns.push_back(p1.name + " played " + p1Card.toString() + ", " + p2.name + " played " + p2Card.toString() + ". " + p1.name + " wins.");
    } else {
        p2.cardsWin += count;
        turns.push_back(p1.name + " played " + p1Card.toString() + ", " + p2.name + " played " + p2Card.toString() + ". " + p2.name + " wins.");
    }
    
}
void Game::printLastTurn() {
    cout<<turns.pop_back()<<endl;
 }

void Game::playAll() {
    while(p1.stacksize()>0 && p2.stacksize()>0)
        this->playTurn();
 }

void Game::printWiner() {
    if(p1.stackSize==0 || p2.stackSize==0){
        if(p1.cardesTaken()>p2.cardesTaken())
            cout<<p1.name<<endl;
        else if(p1.cardesTaken()<p2.cardesTaken())
            cout<<p2.name<<endl;
            else cout<<"draw"<<endl;
    }

 }

void Game::printLog() {
     for (int i = 0; i < turns.size(); i++)
        cout << turns[i] << endl;
 }

void Game::printStats() {
int totalTurns = turns.size();
double p1WinRate = (double)p1.cardsTaken()/2 / totalTurns * 100;
double p2WinRate = (double)p2.cardsTaken()/2 / totalTurns * 100;
double drawRate = draws / totalTurns * 100;

cout << p1.name << " Stats: " << "Win Rate: " << p1WinRate << "%, Cards Won: " << p1.cardsTaken() << endl;
cout << p2.name << " Stats: " << "Win Rate: " << p2WinRate << "%, Cards Won: " << p2.cardsTaken() << endl;
cout << "Draw Rate: " << drawRate << "%, Draws: " << draws << endl;

#endif
