#pragma once
#include "src/interface/entity.h"

class Swordsman : public Entity {
public:
    
    Swordsman(int _player) {
        player_id = _player;
        BASE_MOVE = move = 2;
        power = 5;
        health = 10;
        attack_range = 1;
        visual = 's';
    }
};
