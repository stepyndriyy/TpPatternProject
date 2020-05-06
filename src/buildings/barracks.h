#pragma once
#include<vector>
#include "src/map/gamemap.h"
#include "src/player/player.h"
#include "src/units/units"

class Barracks : public virtual Entity {
protected:
    const char NOTHING = '-';
    int remaining_turns = 0;
    char unit_type;
    std::vector<char> priority_direction = {'l', 'r', 'u', 'd'};

public:
    
    Barracks(int _player);     
    bool is_empty(); 
    void build_archer();     
    void build_swordsman(); 
    void next_turn(); 
    
    std::vector<char> get_priority_direction();
    int get_remaining_turns();
    char get_unit_type(); 
};
