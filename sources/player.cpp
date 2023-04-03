#include "player.hpp"


using namespace ariel;

Player::Player(string name){
    this->name=name;
    this->cardsWin=0;
    this->stackSize= new vector<card>;
}
    int Player :: stacksize(){
        return this->stackSize.size();
}

int Player :: cardesTaken(){
        return this->cardsWin;
}
