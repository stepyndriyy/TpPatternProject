#pragma once
#include<map>
#include<string>
#include "src/map/map.h"
#include "src/buildings/barracks.h"
#include "src/interface/entity.h" 

class Player {
private:
    static int current_player_id;
    int player_id;
    std::string player_name;
public:

    Player(const std::string &name) : player_name(name) {
        player_id = current_player_id++;
    }
    
    int get_player_id() {
        return player_id;
    }

    std::string get_player_name() {
        return player_name;
    }

};

int Player::current_player_id = 1;
