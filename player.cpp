#include "player.hpp"


using namespace ariel;

Player::Player(string name) : name(name), cardsWin(0), stack() {
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
