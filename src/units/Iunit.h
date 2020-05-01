#pragma once

class Iunit {
protected:
    char visual;
    int move;
    int power;
    int attack_range; 
    int player_id;
    int health;

public:
    static int get_power() {
        return power;
    }
    
    int get_health() {
        return health;
    }

    bool operator<(const Iunit &other) const {
        return health < other.health;
    }
};

