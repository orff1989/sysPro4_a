#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>


using namespace std;

namespace coup {

    class Assassin : public Player{

    public:
        Assassin(Game game, string Name) :
                Player(game, Name) {}

        void foreign_aid() {

        }

        void coup(Player duke) {

        }
    };
}