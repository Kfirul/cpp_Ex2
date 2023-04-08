#include "player.hpp"
#include <string>
#include <vector>

using namespace std;
 namespace ariel{
class Game{

    public:

    Player p1;
    Player p2;
    vector<string> turns;
    int draws;

   Game(Player &p1,Player&p2);

    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

};
 }
