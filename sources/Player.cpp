#include "Player.hpp"

namespace coup{
    int Player::coins() {
        return _coins;
    }

    string Player::getName() {
        return _name;
    }

    void Player::income() {
        if(_game->turn()==_name) {
            if(coins()>=10){
                //to do
            }
            _coins++;
            _game->next_turn();
            set_lastCommand("income");
        } else{
            throw "it is not your turn!";
        }
    }


    void Player::coup(Player& p) {
        if(_game->turn()==_name) {
            if(role()=="Assassin" &&coins()>=3){
                _coins-=3;
            } else if(coins()>=7){
                _coins-=7;
            } else{
                throw "you dont have enough money";
            }
            p.setAlive(false);
            string s = "coup ";
            s+=p.getName();
            set_lastCommand(s);
            _game->next_turn();
            if (_game->players().size()==1) _game->setWinner();
        } else{
            throw "it is not your turn!";
        }

    }

    void Player::foreign_aid() {
        if(_game->turn()==_name) {
            _coins+=2;
            set_lastCommand("foreign_aid");
            _game->next_turn();
        } else{
            throw "it is not your turn!";
        }
    }

    void Player::block(Player& p) {
        _game->block(*this,p);
    }

    string Player::role() {
        return "Player";
    }

    void Player::decreasCoins(int num) {
        if (_coins-num>=0){
        _coins-=num;
        }
        else{
            throw "there not enough coins";
        }
    }

    void Player::increaseCoins(int num) {
        _coins+=num;
    }

    bool Player::equels(Player &p) {
        if(_name==p.getName() && _game==p._game && _coins==p.coins() && lastCommand==p.lastCommand){ return true;}
        return false;
    }

    bool Player::isAlive() const {
        return alive;
    }

    void Player::setAlive(bool alive) {
        Player::alive = alive;
    }


}