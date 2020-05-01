#pragma once
#include "src/interface/entity.h"

class Swordsman : public Entity {
public:
    
    Swordsman(int _player) {
        player_id = _player;
        move = 2;
        power = 5;
        health = 15;
        attack_range = 1;
        visual = 's';
    }
};
