#include <card.hpp>
#include <string>

using namespace std;
using namespace ariel;

card::card(int num,string suit){
    this->num=num;
    this->suit=suit;
}

card::compare(card a){
    if(this->num==a.num)
        return 0;

    else if(this->num==1){
        if(a.num==2)
            return -1;
        return 1;
           }

    lse if(a->num==1){
        if(this.num==2)
            return 1;
        return -1;
           }

    else if(this.num>a.num)
        return 1;  

    return -1;          
}