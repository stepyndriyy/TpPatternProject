#include "map.h"

int Map::raw_dist(const Cell &from, const Cell &to) {
    return std::abs(from.x - to.x) + std::abs(from.y - to.y);
}

bool Map::is_in_bound(const Cell &coord) {
    return (0 <= coord.x && coord.x < MAP_SIZE) && (0 <= coord.y && coord.y < MAP_SIZE);
}

Map::Map() {
    map.resize(MAP_SIZE, std::vector<char>(MAP_SIZE, EMPTY_CHAR));
}

int Map::get_size() {
    return MAP_SIZE;
}


bool Map::is_cell_empty(const Cell &coord) {
    return (is_in_bound(coord) && map[coord.y][coord.x] == EMPTY_CHAR);
}

void Map::print() {
    std::cout << " # "; 
    for (int i = 0; i < MAP_SIZE; ++i) {
        std::cout << i << " ";
        if (i < 10)
            std::cout << " ";
    }
    std::cout << '\n'; 

    for (int y = 0; y < MAP_SIZE; ++y) {
        if (y < 10) {
            std::cout << " ";
        }
        std::cout << y << " ";
        for (int x = 0; x < MAP_SIZE; ++x) {
            std::cout << map[y][x] << "  "; 
        }
        std::cout << '\n';
    }
}
