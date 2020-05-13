#include "command.h"

class CommandAttack : public Command {
private:
    Cell from, to;
public:
    CommandAttack(Player &pl, const Cell &fr, const Cell &t) : Command(pl), from(fr), to(t) {}

    void execute() override;
};

void CommandAttack::execute() { 
    if (!map->is_unit(from)) {
        std::cout << "there is no units(\n";
        return;
    }
    Entity *unit = map->get_unit(from);

    if (unit->get_player_id() != player->get_player_id()) {
        std::cout << "it's not your unit\n";
        return;
    } 
    if (unit->move <= 0) {
        std::cout << "not enough moves\n";
        return;
    }
     
    Entity* enemy = map->get_entity(to);
    if (!enemy) {
        std::cout << "you can't attack noting(\n";
        return;
    }    
    if (enemy->get_player_id() == player->get_player_id()) {
        std::cout << "it's your unit\n";
        return;
    } 
    
    if (map->raw_dist(from, to) > unit->get_attack_range()) {
        std::cout << "not in range\n";
        return;
    }
    unit->attack(enemy);
    if (!enemy) {
        map->set_cell_empty(to);
    }
    unit->move = 0;
}


