#pragma once
#include<string>
#include "../buildings/barracks.h"
#include "../interface/entity.h" 

class Player {
private:
    static int current_player_id;
    int player_id;
    std::string player_name;
public:


    Player(const std::string &name) : player_name(name) {
        player_id = current_player_id++;
    }
    
    int get_player_id() const {
        return player_id;
    }

    std::string get_player_name() const {
        return player_name;
    }

};

int Player::current_player_id = 1;
