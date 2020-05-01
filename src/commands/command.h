#pragma once
#include<iostream>
#include<string>
#include<map>
#include "src/map/gamemap.h"
#include "src/interface/entity.h"

class Command {
protected:
    GameMap *map;
    Player player;
    Command(GameMap &_map, const Player &pl) : map(&_map), player(pl) {}

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
        map->move(unit_pos, new_pos); 
        map->print();
        unit_pos = new_pos;
        return true;
    }
    
public:
    CommandMoveUnit(GameMap &map, const Player &pl,  const Cell &pos) : Command(map, pl), unit_pos(pos) {}

    void execute() override {
        if (!map->is_unit(unit_pos)) {
            std::cout << "there is no units(\n";
            return;
        }
        Entity *unit = map->get_unit(unit_pos);

        if (unit->get_player_id() != player.get_player_id()) {
            std::cout << "it's not your unit\n";
            return;
        } 

        const std::map<std::string, Cell> possible_moves = {
            {"u", Cell(0, -1)},
            {"d", Cell(0, 1)},
            {"r", Cell(1, 0)},
            {"l", Cell(-1, 0)}
        };
        std::string direction;
        while (unit->move > 0) {
            std::cin >> direction;
            if (direction == "end") {
                return;
            }
            if (possible_moves.find(direction) == possible_moves.end()) {
                std::cout << "wrong input\n";
            } else if (move(possible_moves.at(direction))) {
                unit->move--;
            } else {
                std::cout << "impossible move\n";
            }
        }        
        std::cout << "no more moves\n";
        return;
    }
};
