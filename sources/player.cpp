#include "player.hpp"


using namespace ariel;

Player::Player(string name) : name(name), cardsWin(), stackSize() {}

    int Player :: stacksize(){
        return this->stackSize.size();
}

int Player :: cardesTaken(){
        return this->cardsWin;
}
