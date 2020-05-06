#pragma once

class Entity {
protected:
    int BASE_MOVE;
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
    
    virtual void attack(Entity* &other) {
        other->health -= power;
        if (other->health <= 0) {
            delete other;
            other = nullptr;
        }
    }

    virtual void update() {
        move = BASE_MOVE;
    }
};

