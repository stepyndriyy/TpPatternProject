#pragma once
#include<iostream>
#include<queue>
#include "map.h"
#include<vector>
#include "src/interface/entity.h"
#include "src/buildings/barracks.h"


class GameMap : public Map {
private:
    static GameMap* global_map;
    std::vector<std::vector<Entity*> > entities;    
   
    GameMap();
    

public:    

    bool is_unit(const Cell &coord);
    bool is_barracks(const Cell &coord);
    bool is_entity(const Cell &coord);

    Entity* get_unit(const Cell &coord);
    Entity* get_entity(const Cell &coord);
    Barracks* get_barracks(const Cell &coord); 
    
    void move(const Cell &from, const Cell &to);
 
    void set_cell(const Cell &pos, Entity *entity);
    void set_cell_empty(const Cell &pos);
    
    void attack(const Cell &from, const Cell &to); 

    int real_dist(const Cell &from, const Cell &to);    

    static GameMap* get_instance(); 
    
};




