#include <iostream>
#include "Assassin.hpp"
#include "Player.hpp"
using namespace std;

namespace coup{
    /*
    constractor
    */   
    Assassin::Assassin(Game game, string name_player){
        this->game = game;
        this->name = name_player;
    }

    void Assassin::coup(Player player){}

}

