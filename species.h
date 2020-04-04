#pragma once
#include<vector>
#include "unique.h"


class Species {
private:
    int amount; 
    std::vector<IUnique*> all_abilities; 
    
public:
    Species(IUnique *Race, IUnique *Ability);

    void attack_effect();
    
    void end_turn_effect();
};

Species::Species(IUnique *Race, IUnique *Ability) {
    all_abilities.resize(2);
    all_abilities[0] = Race;
    all_abilities[1] = Ability; 
}

void Species::attack_effect() {
    for (unsigned i = 0; i < all_abilities.size(); ++i) {
        all_abilities[i]->attack_effect();
    }
}

void Species::end_turn_effect() {
    for (unsigned i = 0; i < all_abilities.size(); ++i) {
        all_abilities[i]->end_turn_effect();
    }
}


