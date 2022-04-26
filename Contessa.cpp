#include <iostream>
#include "Player.hpp"
#include "Contessa.hpp"
using namespace std;

namespace coup{
        /*
        constractor
        */   

        Contessa::Contessa(Game game, string name_player){
            this->game = game;
            this->name = name_player;
        }

        void Contessa::block(Player player){}

}