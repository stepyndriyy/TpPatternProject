#pragma once
#include<vector>
#include<iostream>
#include<cmath>

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
protected:
    const int MAP_SIZE = 6;
    const char EMPTY_CHAR = '.';
    std::vector<std::vector<char> > map;
    
    
    Map();
    
public:
    
    bool is_in_bound(const Cell &coord);
    int get_size();
    int raw_dist(const Cell &from, const Cell &to);
    bool is_cell_empty(const Cell &coord);
    
    void print();    
    
};


