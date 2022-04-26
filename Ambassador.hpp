#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{

    class Ambassador:public Player{ 
        public:
            /*
            constractor
            */   
            Ambassador(Game game, string name_player);

            void transfer(Player player_from, Player player_to);
            
            void block(Player player);
    };
}