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
    return (!is_cell_empty(coord)) && (!is_barracks(coord));
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
    char vis = map[from.y][from.x];
    entities[from.y][from.x] = nullptr;
    entities[to.y][to.x] = cur_unit;
    map[from.y][from.x] = EMPTY_CHAR;
    map[to.y][to.x] = vis;
}

void GameMap::set_cell(const Cell &pos, Entity* entity) {
    entities[pos.y][pos.x] = entity;
    if (!entity) {
        map[pos.y][pos.x] = EMPTY_CHAR;
        return;
    }
    map[pos.y][pos.x] = entity->get_visual();
}

void GameMap::set_cell_empty(const Cell &pos) {
    set_cell(pos, nullptr);
}


int GameMap::real_dist(const Cell &from, const Cell &to) {
    using std::vector;
    vector<vector<int> > dist(MAP_SIZE, vector<int> (MAP_SIZE, -1));
    std::queue<Cell> queue;
    queue.push(from);
    dist[from.y][from.x] = 0;
    while (!queue.empty()) {
        Cell cur = queue.front();
        queue.pop();
        for (Cell diff : {Cell(1, 0), Cell(0, 1), Cell(-1, 0), Cell(0, -1)}) {
            Cell next = cur + diff;
            if (!is_in_bound(next))
                continue;
            if (dist[next.y][next.x] != -1 || !is_cell_empty(next))
                continue;
            dist[next.y][next.x] = dist[cur.y][cur.x] + 1;
            queue.push(next); 
        }   
    }
    return dist[to.y][to.x]; 
}
