#include "Iunit.h"

class Swordsman : public Iunit {
public:
    Swordsman(const int player_) {
        player_id = player_;
        move = 2;
        visual = 's';
        power = 5;
        health = 15;
        attack_range = 1;
    }
};
