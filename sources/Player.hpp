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
            alive= true;

            if (_game->playersSize()>=6){ throw "too much players";}
            if (_game->get_Turn()>0){throw "the game already started";}
            _game->addToGame( this);
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

        int coins() const;

        void foreign_aid();

        void coup(Player& p);

        void block(Player& p);

        virtual string role();

    };
}