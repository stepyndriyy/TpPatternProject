#pragma once

class Entity {
protected:
    int power;
    int attack_range; 
    int player_id;
    char visual;
public:
    int move;
    int health;

    virtual int get_power() {
        return power;
    }
    
    virtual int get_attack_range() {
        return attack_range;
    }

    virtual bool operator<(const Entity &other) const {
        return health < other.health;
    }

    virtual int get_player_id() {
        return player_id;
    }

    virtual char get_visual() {
        return visual;
    }
};

