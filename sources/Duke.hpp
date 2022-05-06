#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace coup {

    class Duke : public Player{

    public:
        Duke(Game& game, string Name) :
        Player(&game, Name) {}

        void tax();

        string role() override;



    };
}