#include "Game.hpp"

namespace coup{
    void Game::addToGame(string& player) {
        cout<<"addTOGame"<<endl;
        _players.push_back(6);
    }

    string Game::turn(){
        if (_players.size() > 0) {
            return "";
        }
        return "";
    }

    void Game::showPlayers(){
        cout<<"showing players"<< endl;
        for (size_t i = 0; i < _players.size(); i++) {
            cout<<_players[i]<<endl;
        }
    }

    vector<string> Game::players(){
        vector<string> vec;
//        for (size_t i = 0; i < _players.size(); i++) {
//            vec.push_back("aa");
//        }
        return vec;
    }

    string Game::winner() {
        return std::string();
    }
}