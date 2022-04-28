#include "Player.hpp"

namespace coup{
    int Player::coins() {
        return _coins;
    }

    string Player::getName() {
        return _name;
    }

    void Player::income() {
        _coins++;
    }

    string Player::role() {
        return _role;
    }

    void Player::coup(Player p) {

    }
}