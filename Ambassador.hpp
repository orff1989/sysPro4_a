
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Game.hpp"



using namespace std;

namespace coup {

    class Ambassador : public Player{

    public:
        Ambassador(Game game, string Name) :
                Player(game, Name) {}

        void transfer(Player duke, Player assassin){

        }

        void foreign_aid() {

        }
    };
}