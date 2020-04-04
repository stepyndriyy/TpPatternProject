#pragma once
#include <string>
#include "species.h"

class Player {
private:
    static unsigned next_player_number;
    
    std::string player_name;
    unsigned coins=5;

    Species current;
    Species previous;


public:
    Player();
};