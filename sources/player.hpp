#ifndef Player_HPP
#define Player_HPP

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{
class Player{
    
    string name;
    vector<card> stack;
    int cardsWin;
    int winCount;
    
    public:

    Player(string name);

    int stacksize();
    int cardesTaken();
    string getName();
    vector<card> getStack();
    int getWinCount();
    void plusCardsWin(int plus);
    void plusWinCount();
    void addCard(card card);
    card play();
};
}

#endif
