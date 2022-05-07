#include "Game.hpp"
#include "Player.hpp"

constexpr unsigned int five = 5;


namespace coup{
    void Game::addToGame(Player* player) {
        _players.push_back(player);
    }

    string Game::turn(){
        if (_players.empty()) {
            throw "there are no player in this game";
        }
        return _players.at(_turn % _players.size())->getName();

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
        if (_winner==-1) {throw "there is no winner yet";}
        return players().at(0);
    }

    string removeFirstWord(const string& str){
        bool flag = false;
        string s;
        for (size_t i = 0; i < str.size(); i++) {
            if(flag){
                s+=str.at(i);
            }
            if(str.at(i)==' ' && !flag){
                flag=true;
            }
        }
        return s;
    }

    void Game::block(Player& blockBy, Player& p){
        string victim;
        Player* pp= nullptr;
        if (p.get_lastCommand()=="unblockable"){ throw "cant block";}
        if(p.get_lastCommand()=="income"){ throw "cant block income function";}

        if(p.get_lastCommand()=="foreign_aid" && blockBy.role() == "Duke"){
            p.decreasCoins(2);
        }
        else if((p.get_lastCommand().substr(0,five)=="steal") && (blockBy.role() == "Ambassador" || blockBy.role() == "Captain")){
            victim= removeFirstWord(p.get_lastCommand());
            pp = findPlayer(victim);
            if(pp== nullptr) {throw "cant find this player";}
            if(!pp->isAlive()){throw "this player is not alive";}

            pp->increaseCoins(2);
            p.decreasCoins(2);
        }
        else if((p.get_lastCommand().substr(0,five)=="coup ") && blockBy.role() == "Contessa"){
            victim= removeFirstWord(p.get_lastCommand());
            pp=findPlayer(victim);
            if(pp== nullptr ){ throw "cant find this player";}
            if(pp->isAlive()) {throw "this person is alive";}

            pp->setAlive(true);
        }
        else{
            throw "you can't block!";
        }
    }

    Player* Game::findPlayer(const string& str) {
        for(size_t i=0; i<_players.size();i++){
            if(_players.at(i)->getName()==str) {return _players.at(i);}
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

    size_t Game::playersSize() {
        return _players.size();
    }

    size_t Game::get_Turn() const {
        return _turn;
    }

}