#include "Iunit.h"

class Archer : public Iunit {
private:
public:
    Archer(const int player_) {
        player_id = player_;
        move = 1;
        visual = 'a';
        power = 5;
        health = 5;
        attack_range = 2;
    }
};
