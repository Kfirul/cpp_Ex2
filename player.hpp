#ifndef Player_HPP
#define Player_HPP

#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{
class Player{
    
    public:
    string name;
    vector<card> stack;
    int cardsWin;
    
    Player(string name);

    int stacksize();
    int cardesTaken();
};
}

#endif
