#include "player.hpp"
#include <string>
#include <vector>

using namespace std;
 namespace ariel{
class Game{

    


    Player &player1;
    Player &player2;
    vector<string> turns;
    int draws;
    
    public:

   Game(Player &player1,Player&player2);
    void shuffleDeck(vector<card>& deck);
    void deals(vector<card>& deck, Player& player1, Player& player2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

};
 }
