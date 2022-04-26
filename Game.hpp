#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<iterator>
#include "Player.hpp"

using namespace std;

namespace coup {

    class Game{
    private:
        vector<string> _vec;
        int _turn;
        int _winner;

    public:
        Game(){
            _turn=0;
            _winner= -1;
        }

        vector<string> players(){
            return vector<string>(_vec);
        };

        string turn(){
            if (_vec.size()>0) {
                return "";
            }
            return "";
        }

        void addToGame(string player){
            _vec.push_back(string(player));
        }

    };
}