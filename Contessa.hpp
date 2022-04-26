#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{

    class Contessa:public Player{
        public:
            /*
            constractor
            */   
            Contessa(Game game, string name_player);
            
            void block(Player player);
    };
}