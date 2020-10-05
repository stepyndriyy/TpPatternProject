#include "barracks.h"

Barracks::Barracks(int _player) : remaining_turns(0), unit_type(NOTHING) {
    player_id = _player;
    BASE_MOVE = move = 0;
    power = 0;
    health = 15;
    attack_range = 0;
    visual = 'B';
}

bool Barracks::is_empty() {
    return (remaining_turns == 0);
}



void Barracks::build_archer() {
    if (!is_empty()){
        return;
    }
    unit_type = 'a';
    remaining_turns = 2;  
}

void Barracks::build_swordsman() {
    if (!is_empty()) {
        return;
    }
    unit_type = 's';
    remaining_turns = 1;
}

void Barracks::next_turn() {
    remaining_turns--;
    if (remaining_turns <= 0) {
        remaining_turns = 0;
        unit_type = NOTHING;
    }
}

std::vector<char> Barracks::get_priority_direction() {
    return priority_direction;
}

char Barracks::get_unit_type() {
    return unit_type;
}

int Barracks::get_remaining_turns() {
    return remaining_turns;
}

