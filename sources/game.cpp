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

Game::Game(Player p1, Player p2) : p1(p1), p2(p2) {
    vector<Card> deck;
    string suitTemp;
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 5; j++) {
            if (j == 1) suitTemp = "heart";
            else if (j == 2) suitTemp = "diamond";
            else if (j == 3) suitTemp = "club";
            else suitTemp = "spade";

            card newCard(i, suitTemp);
            deck.push_back(newCard);
        }
    }

    // Shuffle the deck
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}


void Game::playTurn() { }

void Game::printLastTurn() { }

void Game::playAll() { }

void Game::printWiner() { }

void Game::printLog() { }

void Game::printStats() { }

#endif
