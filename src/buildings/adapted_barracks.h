#pragma once
#include "barracks.h"
#include "../map/gamemap.h"

class BarracksAdapted {
private:
    Barracks* barracks;
    
    Cell position;
    GameMap* map = GameMap::get_instance();
    
    Cell get_vect(char dir); 
    Cell where_to_spawn();   
    bool spawn_archer(); 
    bool spawn_swordsman(); 
    bool spawn_unit(char type); 
    
public:
    BarracksAdapted(Barracks* br, const Cell &cell) : barracks(br), position(cell) {}
    
    void update();
};
