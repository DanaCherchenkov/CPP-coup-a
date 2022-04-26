#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"
using namespace std;

namespace coup{
        /*
        constractor
        */   
        Duke::Duke(Game game, string name){
                this->game = game;
                this->name = name;
        }
        
        void Duke::block(Player palyer){}

        void Duke::tax(){}
}

