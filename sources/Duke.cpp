#include "Duke.hpp"

namespace coup{

    void Duke::tax() {
        if(_game->turn()==_name) {
            _coins+=3;
            _game->next_turn();
            set_lastCommand("tax");
        } else{
            throw "it is not your turn!";
        }
    }

    string Duke::role() {
        return "Duke";
    }


}