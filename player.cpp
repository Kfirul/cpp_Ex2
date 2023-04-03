#include "player.hpp"


using namespace ariel;

Player::Player(string name) : name(name), cardsWin(0), stack() {}

    int Player :: stacksize(){
        return this->stack.size();
}

int Player :: cardesTaken(){
        return this->cardsWin;
}
