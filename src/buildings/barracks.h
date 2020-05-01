#pragma once
#include "src/interface/entity.h"
#include "src/units/archer.h"
#include "src/units/swordman.h"

class Barracks : Entity {
private:
    static const char NOTHING = '-';
    int remainig_turns = 0;
    char unit_type;
public:
    
    static const char visual = 'B';
    
    Barracks(int _player) : remainig_turns(0), unit_type(NOTHING) {
        player_id = _player;
        move = 0;
        power = 0;
        health = 15;
        attack_range = 0;
    }

    char new_turn() {
        remainig_turns--;
        if (remainig_turns == 0) {
            char ans = unit_type;
            unit_type = NOTHING;
            return ans;
        }
        remainig_turns = (remainig_turns > 0) ? remainig_turns : 0;
        return NOTHING;
    }

    bool create_archer() {
        if (remainig_turns != 0) {
            return false;
        }
        remainig_turns = 3;
        /*
        Archer(0) cmp; 
        unit_type = cmp.get_visual();
    */
    }
    
    bool create_swordsman() {
        if (remainig_turns != 0) {
            return false;
        }
      
        remainig_turns = 2;
      /*
        unit_type = Swordsman::visual;
    */
    }
};
