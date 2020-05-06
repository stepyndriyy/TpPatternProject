#include "command.h"

class CommandAttack : public Command {
private:
    Cell unit_pos;
public:
    CommandAttack(Player &pl, const Cell &c) : Command(pl), unit_pos(c) {}

    void execute() override;
};

void CommandAttack::execute() { 
    if (!map->is_unit(unit_pos)) {
        std::cout << "there is no units(\n";
        return;
    }
    Entity *unit = map->get_unit(unit_pos);

    if (unit->get_player_id() != player->get_player_id()) {
        std::cout << "it's not your unit\n";
        return;
    } 
    if (unit->move <= 0) {
        std::cout << "not enough moves\n";
        return;
    }
    Cell enemy_pos;
    std::cin >> enemy_pos.y >> enemy_pos.x;     
     
    Entity* enemy = map->get_entity(enemy_pos);
    if (enemy == nullptr) {
        std::cout << "you can't attack noting(\n";
        return;
    }    
    if (enemy->get_player_id() == player->get_player_id()) {
        std::cout << "it's your unit\n";
        return;
    } 
    if (map->dist(unit_pos, enemy_pos) > unit->get_attack_range()) {
        std::cout << "not in range\n";
        return;
    }
    map->attack(unit_pos, enemy_pos); 
    unit->move = 0;

    map->print();
}


