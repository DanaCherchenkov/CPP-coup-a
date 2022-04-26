#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup{

    string Game::turn(){
        return "Dana";
    }

    vector<string> Game::players(){
        return this->players_names;
    }

    string Game::winner(){
        return "Dana";
    }

}