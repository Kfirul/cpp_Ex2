#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using namespace std;
namespace ariel{
    class card{
        

        int num;
        string suit;

        public:

        card(int num,string suit);

        int compare(card other);
        string toString();
        
    };
}

#endif