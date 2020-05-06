#include "adapted_barracks.h"
#include<iostream>

Cell BarracksAdapted::get_vect(char dir) {
    if (dir == 'l')
        return Cell(-1, 0);
    if (dir == 'r')
        return Cell(1, 0);
    if (dir == 'u') 
        return Cell(0, -1);
    if (dir == 'd')
        return Cell(0, 1);
}

Cell BarracksAdapted::where_to_spawn() {
    for (char dir : barracks->get_priority_direction()) {
        Cell next = get_vect(dir) + position;
        if (map->is_cell_empty(next))
            return next;
    }
    return Cell(-1,-1);
}

bool BarracksAdapted::spawn_archer() {
    Cell cell = where_to_spawn();
    if (cell.x == -1 && cell.y == -1) {
        return false;
    }
    map->set_cell(cell, new Archer(barracks->get_player_id()));
    return true;
}

bool BarracksAdapted::spawn_swordsman() {
    Cell cell = where_to_spawn();
    if (cell.x == -1 && cell.y == -1) {
        return false;
    }
    map->set_cell(cell, new Swordsman(barracks->get_player_id()));
    return true;
}


bool BarracksAdapted::spawn_unit(char type) {
    if (type == 'a') {
        return spawn_archer();
    }
    if (type == 's') {
        return spawn_swordsman();
    }
    return false;
}

void BarracksAdapted::update() {
    if (barracks->get_remaining_turns() == 1) {
        if (!spawn_unit(barracks->get_unit_type())) {
            return;
        }    
    }
    barracks->next_turn();    
}


