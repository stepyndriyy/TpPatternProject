#pragma once
#include<iostream>
#include<string>
#include<map>
#include "src/map/map.h"
#include "src/units/Iunit.h"

class Command {
protected:
    Map *map;
    Player *player;
    Command(Map *_map, Player *pl) : map(_map), player(pl) {}

public:
    virtual void execute() = 0;     

};


class CommandMoveUnit: public Command {
private:
    Cell unit_pos;    

    bool move(const Cell &diff) {
        Cell new_pos = unit_pos + diff;
        if (!map->is_cell_empty(new_pos))
            return false;
        return true;
    }
    
public:
    CommandMoveUnit(Map *map, Player *pl,  const Cell &pos) : Command(map, pl), unit_pos(pos) {}

    void execute() override {
        using std::cout;
        if (!player.is_my_unit(unit_pos)) {
            cout << "not your unit(\n";
            return;   
        }
        Iunit *unit = player.get_unit(unit_pos);
        
        while (unit->move > 0) {
            std::string direction;
            std::cin >> direction;
            if (direction == "end") {
                return;
            }
            const std::map<std::string, Cell> possible_moves = {
                {"u", Cell(0, -1)},
                {"d", Cell(0, 1)},
                {"r", Cell(1, 0)},
                {"l", Cell(-1, 0)}
            };
            if (possible_moves.find(direction) == possible_moves.end()) {
                cout << "wrong input\n";
            } else if (this->move(possible_moves[direction])) {
                unit->move--;
            }
        }        
        cout << "no more moves\n";
        return;
    }
};
