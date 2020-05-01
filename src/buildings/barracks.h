#include "src/units/swordman.h"
#include "src/units/archer.h"
#include<vector>

class Barracks {
private:
    static const char NOTHING = '-';
    int remainig_turns = 0;
    char unit_type;
    int player_id;
public:
    Barracks(int player_) : remainig_turns(0), unit_type(NOTHING), player_id(player_) {}

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
        unit_type = Archer::visual; 
    }
    
    bool create_swordsman() {
        if (remainig_turns != 0) {
            return false;
        }
        remainig_turns = 2;
        unit_type = Swordsman::visual;
    }
};
