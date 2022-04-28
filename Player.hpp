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
        string _role;

    public:
        Player(Game game, string Name) {
            _name = Name;
            _game = game;
            _coins=0;
            _game.addToGame(Name);
        }
        Player(Game game, string Name, string role) {
            _name = Name;
            _game = game;
            _role=role;
            _coins=0;
            _game.addToGame(Name);
        }

        string getName();

        void income();

        int coins();

        string role();

        void coup(Player p);

    };
}