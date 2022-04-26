#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{

    class Assassin:public Player{ 
        public:
            /*
            constractor
            */   
            Assassin(Game game, string name_player);
            
            void coup(Player player);
    };
}
