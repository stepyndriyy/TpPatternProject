#pragma once
#include<map>
#include<string>
#include "src/map/map.h"
#include "src/buildings/barracks.h"
#include "src/unit/Iunit.h" 

class Player {
private:
    static int current_player_id = 1;
    int player_id;
    std::string player_name;
    std::map<Cell, Iunit*>
    std::map<Cell, Barracks*> buildings;
public:

    Player(const std::string &name) : player_name(name), player_id(current_player_id++) {}
    
    bool is_my_unit(const Cell &pos) {
        return units.find(pos) != units.end();
    }
    
    bool is_my_barracks(const Cell &pos) {
        return buildings.find(pos) != buildings.end();
    }
    
    Iunit* get_unit(const Cell &pos) {
        if (!is_my_unit(pos))
            return nullptr;
        return units[pos];
    } 

    Barracks* get_barracks(const Cell &pos) {
        if (!is_my_barracks(pos))
            return nullptr;
        return buildings[pos];
    }
};
