#pragma once
#include<vector>
#include<iostream>

struct Cell {
    int x, y;
    Cell() : x(0), y(0) {}
    Cell(int _x, int _y) : x(_x), y(_y) {}  
    
    bool operator<(const Cell &other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
    
    Cell operator+(const Cell &other) const {
        return Cell(x + other.x, y + other.y);
    }

    friend std::istream& operator>>(std::istream &stream, Cell &cell) {
        stream >> cell.y >> cell.x;
        return stream;  
    }

};

class Map {
private:
    const int MAP_SIZE = 21;
    std::vector<std::vector<char> > map;
    
    bool is_in_bound(const Cell &coord);
public:
    Map();
    
    int get_size();
    void set_cell(const Cell &coord, char c);
    bool is_cell_empty(const Cell &coord);

    void print();    
};


bool Map::is_in_bound(const Cell &coord) {
    return (0 <= coord.x && coord.x < MAP_SIZE) && (0 <= coord.y && coord.y < MAP_SIZE);
}

Map::Map() {
    map.resize(MAP_SIZE, std::vector<char>(MAP_SIZE, '.'));
}

int Map::get_size() {
    return MAP_SIZE;
}

bool Map::is_cell_empty(const Cell &coord) {
    return (is_in_bound(coord) && map[coord.y][coord.x] == '.');
}

void Map::set_cell(const Cell &coord, char c) {
    map[coord.y][coord.x] = c;
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
