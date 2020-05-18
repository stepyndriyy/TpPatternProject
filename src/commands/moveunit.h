#pragma once
#include "command.h"

class CommandMoveUnit: public Command {
private:
    Cell from, to;    
    
public:
    CommandMoveUnit(Player &pl,  const Cell &fr, const Cell &t) : Command(pl), from(fr), to(t) {}

    void execute() override; 
};

void CommandMoveUnit::execute() {
    if (!map->is_unit(from)) {
        std::cout << "there is no units(\n";
        return;
    }
    
    Entity *unit = map->get_unit(from);
    
    if (unit->get_player_id() != player->get_player_id()) {
        std::cout << "it's not your unit\n";
        return;
    } 
    if (!map->is_in_bound(to)) {
        return;
    } 
    int dist = map->real_dist(from, to);
    if (dist == -1 || dist > unit->move) {
        std::cout << "you can't move there\n";
        return;
    }
    unit->move -= dist;
    map->move(from, to);
}

