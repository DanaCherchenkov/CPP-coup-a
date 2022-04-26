#include <iostream>
#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace std;
using namespace coup;


//-------------GOOD INPUT----------------------------
TEST_CASE("Create game - good input"){
    CHECK_NOTHROW(Game game1{});
    CHECK_NOTHROW(Game game2{});
    CHECK_NOTHROW(Game game3{});
}


TEST_CASE("Good input players list"){
    Game game1{};
    Game game2{};
    Duke duke(game1, "Moshe");
    Duke duke1(game1, "Dana");
    Duke duke2(game1, "Lian");
    Duke duke3(game1, "Margol");
    Duke duke4(game2, "Miri");
    Duke duke5(game2, "Mor");
    Duke duke6(game2, "Regina");

    vector<string> players = game1.players();
    vector<string> players_check = {"Moshe", "Dana", "Lian", "Margol"};
    for(size_t i = 0; i < players.size(); i++){
        CHECK(players[i] == players_check[i]);
	}

    vector<string> players1 = game2.players();
    vector<string> players_check1 = {"Miri", "Mor", "Regina"};
    for(size_t i = 0; i < players1.size(); i++){
        CHECK(players1[i] == players_check1[i]);
	}
}


TEST_CASE("Good coins count"){
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

    CHECK(game_1.turn() == "Moshe");
    duke.income();
    CHECK(game_1.turn() == "Yossi");
    assassin.income();
    CHECK(game_1.turn() == "Meirav");
    ambassador.foreign_aid();
    CHECK(game_1.turn() == "Reut");
    captain.income();
    CHECK(game_1.turn() == "Gilad");
    contessa.foreign_aid();

    CHECK(duke.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(ambassador.coins() == 2);
    CHECK(captain.coins() == 1);
    CHECK(contessa.coins() == 2);
}


TEST_CASE("Good test to block & coup functions"){
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

    duke.income();
    assassin.income();
    ambassador.foreign_aid();
    captain.income();
    contessa.foreign_aid();
    CHECK(contessa.coins() == 2);
    duke.block(contessa);
    CHECK(contessa.coins() == 0);
    assassin.foreign_aid();
    CHECK(assassin.coins() == 3);
    ambassador.foreign_aid();
    captain.income();
    contessa.foreign_aid();
    duke.income();
    assassin.coup(captain);
    CHECK(assassin.coins() == 0);
}


TEST_CASE("Good input for steal/transfer functions"){
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

    CHECK(game_1.turn() == "Moshe");
    duke.foreign_aid();
    CHECK(game_1.turn() == "Yossi");
    assassin.foreign_aid();
    CHECK(game_1.turn() == "Meirav");
    ambassador.income();
    CHECK(game_1.turn() == "Reut");
    captain.income();
    CHECK(game_1.turn() == "Gilad");
    contessa.foreign_aid();
    CHECK(game_1.turn() == "Moshe");
    duke.foreign_aid();
    CHECK(game_1.turn() == "Yossi");
    assassin.foreign_aid();
    CHECK(duke.coins() == 4);
    CHECK(captain.coins() == 1);
    ambassador.transfer(duke, captain);
    CHECK(captain.coins() == 2);
    CHECK(duke.coins() == 3);
    captain.steal(duke);
    CHECK(duke.coins() == 1);
    CHECK(captain.coins() == 4);
}


TEST_CASE("Good game"){
    Game game{};
    Duke duke{game, "Dana"};
    Assassin assassin{game, "Maor"};
    Captain captain{game, "Regina"};

    vector<string>players_list = {"Dana", "Maor", "Regina"};
    CHECK(game.players() == players_list);

    duke.foreign_aid();
    assassin.foreign_aid();
    captain.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    captain.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    captain.foreign_aid();
    duke.block(assassin);
    assassin.income();
    captain.foreign_aid();
    duke.foreign_aid();
    assassin.coup(captain);

    vector<string>players_list1 = {"Dana", "Maor"};
    CHECK(game.players() == players_list);

    duke.coup(assassin);
    vector<string>players = {"Dana"};
    CHECK(game.players() == players_list);
    CHECK(game.winner() == "Dana");
}


//-------------BAD INPUT----------------------------
TEST_CASE("Bad input players"){
    Game game1{};
    Game game2{};
    Duke duke(game1, "Miri");
    Assassin asi(game2, "Michael");
    CHECK_THROWS(duke.income()); //at least need to be two players to start the game
    CHECK_THROWS(asi.income());

    Duke duke1{game1, "Moshe"};
	Assassin assassin{game1, "Yossi"};
	Ambassador ambassador{game1, "Meirav"};
	Captain captain{game1, "Reut"};
	Contessa contessa{game1, "Gilad"};
    CHECK_THROWS(Contessa contessa1(game1, "Gili")); //too mach players
}


TEST_CASE("Bad coins count"){
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

    duke.income();
    assassin.income();
    ambassador.foreign_aid();
    captain.income();
    contessa.foreign_aid();
    duke.income();
    assassin.income();
    ambassador.foreign_aid();
    captain.income();
    contessa.foreign_aid();
    duke.income();
    assassin.income();
    ambassador.foreign_aid();
    captain.income();
    contessa.foreign_aid();
    duke.income();
    assassin.income();
    ambassador.foreign_aid();
    captain.income();
    contessa.foreign_aid();
    duke.income();
    assassin.income();
    ambassador.foreign_aid();
    captain.income();
    contessa.foreign_aid();
    CHECK_THROWS(contessa.foreign_aid());
    CHECK_THROWS(ambassador.foreign_aid());
}


TEST_CASE("Bed test to block & coup functions"){
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};

    duke.income();
    assassin.income();
    ambassador.foreign_aid();
    duke.foreign_aid();
    assassin.income();
    ambassador.foreign_aid();
    duke.income();
    CHECK_THROWS(assassin.coup(duke)); //the assassin not have enough money to do the action.
    assassin.income();
    CHECK_THROWS(ambassador.coup(assassin));

}


TEST_CASE("Bad input for steal/transfer functions"){
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.income();
    captain.income();
    contessa.income();
    duke.foreign_aid();
    assassin.foreign_aid();
    CHECK_THROWS(ambassador.transfer(duke, duke));
    ambassador.income();
    CHECK_THROWS(captain.steal(contessa));
}