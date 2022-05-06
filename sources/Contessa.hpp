#include <iostream>
#include <string>
#include "Player.hpp"
#include "Game.hpp"



using namespace std;

namespace coup {

    class Contessa : public Player{

    public:
        Contessa(Game& game, string Name) :
                Player(&game, Name) {}

        string role() override;
    };
}