#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using namespace std;
namespace ariel{
    class card{
        public:

        int num;
        string suit;

        card(int num,string suit);

        int compare(card a);
        string toString();
        
    };
}

#endif