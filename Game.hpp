#include <iostream>
#include <vector>
#pragma once

using namespace std;

namespace coup{

    class Game{
        private:
            vector<string> players_names;
            int num;

        public: 
            string turn();
            vector<string> players();
            string winner();
    };


}