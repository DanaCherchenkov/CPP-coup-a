#include <iostream>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{

    class Captain:public Player{
        public:
            /*
            constractor
            */   
            Captain(Game game, string name_player);

            void block(Player player);
            
            void steal(Player player);
    };
}