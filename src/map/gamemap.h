#pragma once
#include "map.h"
#include<vector>
#include "src/interface/entity.h"
#include "src/buildings/barracks.h"


class GameMap : public Map {
private:
    std::vector<std::vector<Entity*> > entities;    
public:
    GameMap();

    bool is_unit(const Cell &coord);
    bool is_barracks(const Cell &coord);

    Entity* get_unit(const Cell &coord);
    Barracks* get_barracks(const Cell &coord); 
    
    void move(const Cell &from, const Cell &to);
    
    void set_cell(const Cell &pos, Entity *entity);
    void set_cell_empty(const Cell &pos);
};


GameMap::GameMap() : Map() {
    entities.resize(MAP_SIZE, std::vector<Entity*> (MAP_SIZE, nullptr));
}

bool GameMap::is_barracks(const Cell &coord) {
    if (Barracks *b = dynamic_cast<Barracks*>(entities[coord.y][coord.x])) {
        return true;
    }
    return false;
}

bool GameMap::is_unit(const Cell &coord) {
    return ((!is_cell_empty(coord)) && (!is_barracks(coord)));
}

Entity* GameMap::get_unit(const Cell &coord) {
    if (!is_unit(coord))
        return nullptr;
    return entities[coord.y][coord.x]; 
}

Barracks* GameMap::get_barracks(const Cell &coord) {
    if (!is_barracks(coord))
        return nullptr;
    return dynamic_cast<Barracks*>(entities[coord.y][coord.x]);
}

void GameMap::move(const Cell &from, const Cell &to) {
    if (is_cell_empty(from))
        return;
    Entity* cur_unit = entities[from.y][from.x];

    entities[from.y][from.x] = nullptr;
    entities[to.y][to.x] = cur_unit;
    map[to.y][to.x] = map[from.y][from.x];
    map[from.y][from.x] = EMPTY_CHAR;
}

void GameMap::set_cell(const Cell &pos, Entity* entity) {
    entities[pos.y][pos.x] = entity;
    map[pos.y][pos.x] = entity->get_visual();
}

void GameMap::set_cell_empty(const Cell &pos) {
    set_cell(pos, nullptr);
}

