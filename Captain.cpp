#include <iostream>
#include "Captain.hpp"
#include "Game.hpp"
using namespace std;

namespace coup{
    /*
    constractor
    */   
    Captain::Captain(Game game, string name_player){
        this->game = game;
        this->name = name_player;
    }

    void Captain::block(Player player){}

    void Captain::steal(Player player){}  
}