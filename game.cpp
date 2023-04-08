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

Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2), turns(), draws(0)
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

    // Shuffle the deck
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    // Divides the deck between the players
    for (int i = 0; i < deck.size(); i++)
    {
        if (i % 2 == 0)
            this->p1.stack.push_back(deck[static_cast<std::vector<int>::size_type>(i)]);
        else
            this->p2.stack.push_back(deck[static_cast<std::vector<int>::size_type>(i)]);
    }
}

void Game::playTurn()
{
    string str="";
    if (&p1 == &p2)
        throw invalid_argument("Same player");

    if (p1.stack.size() == 0 || p2.stack.size() == 0)
        throw runtime_error("Cannot play turn, one player has an empty stack");

    card p1Card = p1.stack[0];
    card p2Card = p2.stack[0];
    p1.stack.erase(p1.stack.begin());
    p2.stack.erase(p2.stack.begin());
    int count = 2;

    while (p1Card.compare(p2Card) == 0)
    {
        str+= p1.name + " played " + p1Card.toString() + ", " + p2.name + " played " + p2Card.toString() + ". Draw. ";
        draws++;
        if (p1.stack.size() == 0 || p2.stack.size() == 0)
        {
            cout << "The game is over with a draw on the last turn" << endl;
            p1.cardsWin = +count / 2;
            p2.cardsWin = +count / 2;
            return;
        }
        // put the card upside downs
        p1Card = p1.stack[0];
        p2Card = p2.stack[0];
        p1.stack.erase(p1.stack.begin());
        p2.stack.erase(p2.stack.begin());
        count += 2;
        if (p1.stack.size() == 0 || p2.stack.size() == 0)
        {
            cout << "The game is over with a draw on the last turn" << endl;
            p1.cardsWin = +count / 2;
            p2.cardsWin = +count / 2;
            return;
        }
        p1Card = p1.stack[0];
        p2Card = p2.stack[0];
        p1.stack.erase(p1.stack.begin());
        p2.stack.erase(p2.stack.begin());
        count += 2;
    }

    if (p1Card.compare(p2Card) == 1)
    {
        p1.cardsWin += count;
        str+= p1.name + " played " + p1Card.toString() + ", " + p2.name + " played " + p2Card.toString() + ". " + p1.name + " wins.";
        p1.winCount++;
    }
    else
    {
        str+=p1.name + " played " + p1Card.toString() + ", " + p2.name + " played " + p2Card.toString() + ". " + p2.name + " wins.";
        p2.cardsWin += count;
        p2.winCount++;
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
    while (p1.stacksize() > 0 && p2.stacksize() > 0)
        this->playTurn();
}

void Game::printWiner()
{
    if (p1.stacksize() == 0 || p2.stacksize() == 0)
    {
        if (p1.cardesTaken() > p2.cardesTaken())
            cout << p1.name << endl;
        else if (p1.cardesTaken() < p2.cardesTaken())
            cout << p2.name << endl;
        else
            cout << "draw" << endl;
    }
    else
        cout << "The game is not finish yet"<<endl;
}

void Game::printLog()
{
    for (int i = 0; i < turns.size(); i++)
        cout << turns[static_cast<std::vector<int>::size_type>(i)] << endl;
}

void Game::printStats()
{
    int totalTurns = turns.size();
    double p1WinRate = (double)p1.winCount / totalTurns * 100;
    double p2WinRate = (double)p2.winCount / totalTurns * 100;
    double drawRate = (double)draws / totalTurns * 100;


    cout << p1.name << " Stats: "
         << "Win Rate: " << p1WinRate << "%, Cards Won: " << p1.cardesTaken() << endl;
    cout << p2.name << " Stats: "
         << "Win Rate: " << p2WinRate << "%, Cards Won: " << p2.cardesTaken() << endl;
    cout << "Draw Rate: " << drawRate << "%, Draws: " << draws << endl;
}

#endif
