#pragma once
#include "Game.hpp"
#include <iostream>
#include <string>


using namespace std;

namespace coup {

    class Player {
    protected:
        string _name;
        int _coins;
        Game *_game;
        string lastCommand;
        bool alive;
    public:
        bool isAlive() const;

        void setAlive(bool alive);

    public:

        Player(Game *game, string Name) {
            _name = Name;
            _game = game;
            _coins=0;
            _game->addToGame( this);
            alive= true;
        }

        void set_lastCommand(string c){
            lastCommand=c;
        }

        string get_lastCommand(){
            return lastCommand;
        }

        void decreasCoins(int num);

        void increaseCoins(int num);

        string getName();

        void income();

        int coins();

        void foreign_aid();

        void coup(Player& p);

        void block(Player& p);

        bool equels(Player& p);

        virtual string role();

    };
}