#include "player.hpp"

//includes
using namespace ariel;

Player::Player(string name) : name(name), cardsWin(0), stack(), winCount(0) {
    // Constructor for Player class, initializes the name, cardsWin, stack and winCount variables
    if (this->name.empty()) {
        // If the player name is empty, throw a runtime error
        throw runtime_error("Player names cannot be empty");
    }
}

int Player::stacksize(){
    // Returns the number of cards in the player's stack
    return this->stack.size();
}

int Player::cardesTaken(){
    // Returns the number of cards the player has won
    return this->cardsWin;
}

string Player::getName(){
    // Returns the name of the player
    return this->name;
}

vector<card> Player::getStack(){
    // Returns the stack of cards the player currently holds
    return this->stack;
}

int Player::getWinCount(){
    // Returns the number of times the player has won a game
    return this->winCount;
}

void Player::plusCardsWin(int plus){
    // Adds the given number of cards to the player's cardsWin count
    this->cardsWin += plus;
}

void Player::plusWinCount(){
    // Increases the player's winCount by 1
    this->winCount++;
}

void Player::addCard(card card){
    // Adds a card to the player's stack
    this->stack.push_back(card);
}

card Player::play(){
    // Removes and returns the top card from the player's stack
    card playCard = stack.back();
    stack.pop_back();
    return playCard;
}

