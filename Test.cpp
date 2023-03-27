#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

#include "doctest.h"
#include <iostream>
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("1"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);


}

TEST_CASE("2"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    for(int i=0;i<5;i++){
        game.playTurn();

        CHECK(p1.stacksize()+p1.cardesTaken()+p2.stacksize()+p2.cardesTaken()==52);
    }
}

TEST_CASE("3"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    int i=0;
    while(i<15 && p2.stacksize()>0 && p1.stacksize()>0){
        game.playTurn();
        i++;
    }
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
}

TEST_CASE("4"){
Player p1("Alice");
Player p2("Bob");
Game game(p1,p2);

CHECK_NOTHROW(game.printWiner());
CHECK_NOTHROW(game.printStats());
CHECK_NOTHROW(game.printLog());
CHECK_NOTHROW(game.printLastTurn());
}

TEST_CASE("5"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    int i=0;
    while(i< 5&& p2.stacksize()>0 && p1.stacksize()>0){
        CHECK_NOTHROW(game.playTurn());
        i++;
    }
}