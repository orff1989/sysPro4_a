#include "doctest.h"
#include <string>

#include "sources/Duke.hpp"
#include "sources/Assassin.hpp"
#include "sources/Ambassador.hpp"
#include "sources/Captain.hpp"
#include "sources/Contessa.hpp"
#include "sources/Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
using namespace coup;


TEST_CASE("Good input") {
    Game g1{};
    Duke duke{g1, "or1"};
    Assassin assassin{g1, "or2"};
    Ambassador ambassador{g1, "or3"};
    Captain captain{g1, "or4"};
    Contessa contessa{g1, "or5"};

    vector<string> g1Players = g1.players();
    string s;
    for(string name : g1Players){
        s+=name;
        s+=" ";
    }
    CHECK(s=="or1 or2 or3 or4 or5 ");

    //gives every player 4 coins
    for (size_t i = 0; i < 4; i++) {
        CHECK(g1.turn() == "or1");
        duke.income();
        CHECK(g1.turn() == "or2");
        assassin.income();
        CHECK(g1.turn() == "or3");
        ambassador.income();
        CHECK(g1.turn() == "or4");
        captain.income();
        CHECK(g1.turn() == "or5");
        contessa.income();
        CHECK(g1.turn() == "or1");
    }

    CHECK_NOTHROW(duke.tax()); //duke gets 3 more coins, total 7 coins
    CHECK(duke.coins()==7);

    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(duke.block(assassin));
    CHECK(assassin.coins()==4);

    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(captain.steal(duke));
    CHECK_NOTHROW(ambassador.block(captain));
    CHECK(captain.coins()==4);
    CHECK(duke.coins()==7);

    contessa.income();
    CHECK_NOTHROW(duke.tax());
    CHECK(duke.coins()==10);

    CHECK_NOTHROW(assassin.coup(contessa));
    CHECK(assassin.coins()==1);
    ambassador.foreign_aid();
    captain.foreign_aid();
    CHECK(ambassador.coins()==8);
    CHECK(captain.coins()==6);
    CHECK_NOTHROW(duke.coup(captain));

    assassin.foreign_aid();
    ambassador.income();
    duke.tax();

    CHECK_NOTHROW(assassin.coup(ambassador));
    duke.tax();
    assassin.foreign_aid();
    duke.tax();
    assassin.foreign_aid();
    duke.tax();
    CHECK_NOTHROW(assassin.coup(duke));
    CHECK(g1.winner()=="or2");
}

TEST_CASE("Bad input"){
    Game g1{};
    Duke duke{g1, "or1"};
    Assassin assassin{g1, "or2"};
    Ambassador ambassador{g1, "or3"};
    Captain captain{g1, "or4"};
    Contessa contessa{g1, "or5"};

    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());

    duke.tax();
    CHECK_THROWS(duke.tax());
    CHECK_THROWS(duke.coup(contessa));

    CHECK_THROWS(g1.winner());

}