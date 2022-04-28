#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<iterator>


using namespace std;

namespace coup {

    class Game{

        std::vector<int> _players;
        int _turn;
        int _winner;

    public:
        Game(){
            _turn=0;
            _winner= -1;
            _players=vector<int>(5);
        }

        vector<string> players();

        string turn();

        void addToGame(string& player);

        void showPlayers();

        string winner();
    };
}