#include <iostream>
#include "Game.hpp"
#pragma once
using namespace std;

namespace coup{
    
    class Player{
        protected:
            Game game;
            string player_role;
            int player_coins;
            string name;

        public: 
            void income();

            void foreign_aid();

            void coup(Player);

            string role();
            
            int coins();
    };
}