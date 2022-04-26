#pragma once
#include "Game.hpp"
#include <iostream>
#include <string>


using namespace std;

namespace coup {

    class Player {
    private:
        string _name;
        int _coins;
        Game _game;

    public:
        Player(Game game, string Name) {
            _name = string(Name);
            _game = game;
        }

        string getName() {
            return _name;
        }

        void income(){
            _coins++;
        }

        int coins(){
            return _coins;
        }

    };
}