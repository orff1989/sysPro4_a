#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

namespace coup {
    class Player;

    class Game{

        std::vector<Player*> _players;
        size_t _turn;
    public:


    private:
        int _winner;

    public:
        Game(){
            _turn=0;
            _winner= -1;
        }

        vector<string> players();

        string turn();

        size_t get_Turn() const;

        void addToGame(Player* player);

        void next_turn();

        void showPlayers();

        string winner();

        void setWinner();

        Player* findPlayer(const string& str);

        void block(Player& blockBy, Player& p);

        size_t playersSize();

    };
}