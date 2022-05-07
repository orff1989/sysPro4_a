#include "Player.hpp"

constexpr unsigned int seven = 7;
constexpr unsigned int ten = 10;

namespace coup{
    int Player::coins() const{
        return _coins;
    }

    string Player::getName() {
        return _name;
    }

    void Player::income() {
        if (_game->playersSize()<2){ throw "too few players";}
        if(_game->turn()==_name) {
            if(coins()>=ten){
              throw "you have to coup";
            }
            _coins++;
            _game->next_turn();
            set_lastCommand("income");
        } else{
            throw "it is not your turn!";
        }
    }


    void Player::coup(Player& p) {
        bool flag= false;
        if(p.isAlive()) {
            if(coins()>=seven){
                _coins-=seven;
                if (role()=="Assassin"){
                    flag=true;
                }
            } else if(role()=="Assassin" &&coins()>=3){
                _coins-=3;
            } else{
                throw "you dont have enough money";
            }
            p.setAlive(false);
            string s="unblockable";
            if (!flag) {
                s = "coup ";
                s += p.getName();
            }
            set_lastCommand(s);
            _game->next_turn();
            if (_game->players().size()==1) {_game->setWinner();}
        } else{
            throw "this player is dead!";
        }

    }

    void Player::foreign_aid() {
        if (_game->playersSize()<2){ throw "too few players";}
        if(_game->turn()==_name) {
            if(coins()>=ten){
                throw "you have to coup";
            }
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


    bool Player::isAlive() const {
        return alive;
    }

    void Player::setAlive(bool alive) {
        Player::alive = alive;
    }


}