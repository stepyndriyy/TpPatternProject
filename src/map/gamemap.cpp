#include "gamemap.h"

GameMap* GameMap::global_map = nullptr;

GameMap* GameMap::get_instance() {
    if (global_map == nullptr) {
        global_map = new GameMap();
    }
    return global_map;
}

GameMap::GameMap() : Map() {
    entities.resize(MAP_SIZE, std::vector<Entity*> (MAP_SIZE, nullptr));
}

bool GameMap::is_barracks(const Cell &coord) {
    if (!is_in_bound(coord))
        return false;
    if (Barracks *b = dynamic_cast<Barracks*>(entities[coord.y][coord.x])) {
        return true;
    }
    return false;
}

bool GameMap::is_unit(const Cell &coord) {
    if (!is_in_bound(coord))
        return false;
    return ((!is_cell_empty(coord)) && (!is_barracks(coord)));
}

Entity* GameMap::get_unit(const Cell &coord) {
    if (!is_unit(coord) || is_barracks(coord))
        return nullptr;
    return entities[coord.y][coord.x]; 
}

bool GameMap::is_entity(const Cell &coord) {
    if (!is_in_bound(coord))
        return false;
    return (!is_cell_empty(coord));
}

Entity* GameMap::get_entity(const Cell &coord) {
    if (!is_entity(coord))
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


void GameMap::attack(const Cell &from, const Cell &to) {
    Entity* unit = get_entity(from);
    Entity* enemy = get_entity(to);
    if (unit == nullptr || enemy == nullptr) {
        return;
    }
    unit->attack(enemy);
    entities[to.y][to.x] = enemy;
    if (enemy == nullptr) {
         map[to.y][to.x] = EMPTY_CHAR;
    }
}
