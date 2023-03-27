#ifndef GAME_HPP
#define GAME_HPP

#include "game.hpp"
#include <string>

using namespace std;
using namespace ariel;

Game::Game(Player p1, Player p2) : p1(p1), p2(p2) {}

void Game::playTurn() { }

void Game::printLastTurn() { }

void Game::playAll() { }

void Game::printWiner() { }

void Game::printLog() { }

void Game::printStats() { }

#endif
