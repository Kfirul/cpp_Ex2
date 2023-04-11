#ifndef GAME_HPP
#define GAME_HPP

#include "game.hpp"
#include "card.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;
using namespace ariel;

Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2), turns(), draws(0)
{
    vector<card> deck;
    for (int i = 1; i < 14; i++)
    {
        card newCard1(i, "Hearts");
        deck.push_back(newCard1);
        card newCard2(i, "Diamonds");
        deck.push_back(newCard2);
        card newCard3(i, "Clubs");
        deck.push_back(newCard3);
        card newCard4(i, "Spades");
        deck.push_back(newCard4);
    }
    shuffleDeck(deck);
    deals(deck,player1,player2);
}

void Game::shuffleDeck(vector<card>& deck){// Shuffles the given deck of cards.
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}
void Game::deals(vector<card>& deck, Player& player1, Player& player2){// Deals the deck of cards between the two players.
     // Divides the deck between the players
     for (size_t i = 0; i < deck.size(); i++)
    {
        if (i % 2 == 0)
            player1.addCard(deck[i]);
        else
            player2.addCard(deck[i]);
    }
   
}


void Game::playTurn()
{

    string str="";
    if (&player1 == &player2)
        throw invalid_argument("Same player");

    if (player1.stacksize() == 0 || player2.stacksize() == 0)
        throw runtime_error("Cannot play turn, one player has an empty stack");

    card player1Card = player1.play();
    card player2Card = player2.play();
    int count = 2;

    while (player1Card.compare(player2Card) == 0)
    {
        str+= player1.getName() + " played " + player1Card.toString() + ", " + player2.getName() + " played " + player2Card.toString() + ". Draw. ";
        draws++;
        if (player1.stacksize() == 0 || player2.stacksize() == 0)
        {
            cout << "The game is over with a draw on the last turn" << endl;
            player1.plusCardsWin(count / 2);
            player2.plusCardsWin(count / 2);
            return;
        }
        // put the card upside downs
    player1.play();
    player2.play();
    player1Card = player1.play();
    player2Card = player2.play();
    
        count += 4;
    }

    if (player1Card.compare(player2Card) == 1)
    {
        player1.plusCardsWin(count);
        str+= player1.getName() + " played " + player1Card.toString() + ", " + player2.getName() + " played " + player2Card.toString() + ". " + player1.getName() + " wins.";
        player1.plusWinCount();
    }
    else
    {
        str+=player1.getName() + " played " + player1Card.toString() + ", " + player2.getName() + " played " + player2Card.toString() + ". " + player2.getName() + " wins.";
        player2.plusCardsWin(count);
        player2.plusWinCount();
    }
    turns.push_back(str);
    
}
void Game::printLastTurn()
{
    if (turns.empty())
    {
        throw runtime_error("Cannot print last turn, no turns have been played yet");
    }
    cout << turns[turns.size() - 1] << endl;
}

void Game::playAll()
{
    
    while (player1.stacksize() > 0 && player2.stacksize() > 0)
        this->playTurn();
}

void Game::printWiner()
{
    if (player1.stacksize() == 0 || player2.stacksize() == 0)
    {
        if (player1.cardesTaken() > player2.cardesTaken())
            cout << player1.getName() << endl;
        else if (player1.cardesTaken() < player2.cardesTaken())
            cout << player2.getName() << endl;
        else
            cout << "draw" << endl;
    }
    else
        cout << "The game is not finish yet"<<endl;
}

void Game::printLog()
{
    for (size_t i = 0; i < turns.size(); i++)
        cout << turns[i] << endl;
}

void Game::printStats()
{
    int totalTurns = turns.size();
    double player1WinRate = (double)player1.getWinCount() / totalTurns * 100;
    double player2WinRate = (double)player2.getWinCount() / totalTurns * 100;
    double drawRate = (double)draws / totalTurns * 100;


    cout << player1.getName() << " Stats: "
         << "Win Rate: " << player1WinRate << "%, Cards Won: " << player1.cardesTaken() << endl;
    cout << player2.getName() << " Stats: "
         << "Win Rate: " << player2WinRate << "%, Cards Won: " << player2.cardesTaken() << endl;
    cout << "Draw Rate: " << drawRate << "%, Draws: " << draws << endl;
}

#endif
