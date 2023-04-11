#include "player.hpp"


using namespace ariel;

Player::Player(string name) : name(name), cardsWin(0), stack(),winCount(0) {
        if (this->name.empty()) {
        throw runtime_error("Player names cannot be empty");
    }
}

    int Player :: stacksize(){
        return this->stack.size();
}

int Player :: cardesTaken(){
        return this->cardsWin;
}

string Player :: getName(){// Returns the player's name
        return this->name;
    }

vector<card> Player :: getStack(){
    return this->stack;
}     

int Player :: getWinCount(){
    return this->winCount;
}

void Player :: plusCardsWin(int plus){
    this->cardsWin+=plus;
}

void Player :: plusWinCount(){
    this->winCount++;
}

void Player::addCard(card card){ // Adds a card to the player's stack
        this->stack.push_back(card);
    }

card Player::play(){
        card playCard = stack.back();
        stack.pop_back();
        return playCard;
}
