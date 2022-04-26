#include <iostream>
#include "Player.hpp"
#include "Ambassador.hpp"
using namespace std;

namespace coup{
    /*
    constractor
    */   
    Ambassador::Ambassador(Game game, string name_player){
        this->game = game;
        this->name = name_player;
    }

    void Ambassador::transfer(Player player_from, Player player_to){}

    void Ambassador::block(Player player){}
}