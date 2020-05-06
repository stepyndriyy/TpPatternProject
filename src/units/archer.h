#pragma once
#include "src/interface/entity.h"

class Archer : public Entity {
private:
public:
    
    Archer(int _player) {
        player_id = _player;
        BASE_MOVE = move = 1;
        power = 5;
        health = 5;
        attack_range = 2;
        visual = 'a';
    }
};
