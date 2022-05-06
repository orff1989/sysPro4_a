#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    void Game::addToGame(Player* player) {
        _players.push_back(player);
    }

    string Game::turn(){
        if (_players.size() == 0) {
            throw "there are no player in this game";
        }
        else{
        return _players.at(_turn % _players.size())->getName();
        }
    }

    void Game::showPlayers(){
        cout<<"showing players"<< endl;
        for (size_t i = 0; i < _players.size(); i++) {
            cout<<_players[i]->getName()<<endl;
        }
    }

    vector<string> Game::players(){
        vector<string> vec;
        for (size_t i = 0; i < _players.size(); i++) {
            if(_players.at(i)->isAlive()) {
                vec.push_back(_players.at(i)->getName());
            }
        }
        return vec;
    }

    string Game::winner() {
        if (_winner==-1) throw "there is no winner yet";
        return players().at(0);
    }

    string getTheKword(string str , size_t k){
        size_t c=1;
        string s;
        for (size_t i = 0; i < str.size(); i++) {
            if(str.at(i)==' '){
                c++;
                i++;
            }
            if(c==k){
                s+=str.at(i);
            }
        }
        return s;
    }

    void Game::block(Player& blockBy, Player& p){
        string victim;
        Player* pp;

        if(p.get_lastCommand()=="income"){ throw "cant block income function";}
        else if(p.get_lastCommand()=="foreign_aid" && blockBy.role() == "Duke"){
            p.decreasCoins(2);
        }
        else if((p.get_lastCommand().substr(0,5)=="steal") && (blockBy.role() == "Ambassador" || blockBy.role() == "Captain")){
            victim= getTheKword(p.get_lastCommand(), 2);
            pp = findPlayer(victim);
            if(pp== nullptr) throw "cant find this player";
            else if(pp->isAlive()==false){throw "this player is not alive";}
            else{
                pp->increaseCoins(2);
                p.decreasCoins(2);
            }
        }
        else if((p.get_lastCommand().substr(0,5)=="coup ") && blockBy.role() == "Contessa"){
            victim= getTheKword(p.get_lastCommand(), 2);
            pp=findPlayer(victim);
            if(pp== nullptr || pp->isAlive()) throw "cant recover this player";
            else {
               pp->setAlive(true);
            }
        }
        else{
            cout<<"block by: "<< blockBy.getName()<< " role:"<< p.get_lastCommand()<<endl;
            throw "you can't block!";
        }
    }

    Player* Game::findPlayer(string str) {
        for(size_t i=0; i<_players.size();i++){
            if(_players.at(i)->getName()==str) return _players.at(i);
        }
        return nullptr;
    }

    void Game::setWinner() {
        _winner=1;
    }


    void Game::next_turn() {
        _turn++;
        while(!findPlayer(turn())->isAlive()){
            _turn++;
        }

    }
}