#include "command.h"

class CommandBarracks : public Command {
private:
    Cell barracks_pos;
    std::string unit_name;
public:
    CommandBarracks(Player &pl, const Cell &c, const std::string &str) : Command(pl), barracks_pos(c), unit_name(str) {}

    void execute() override { 
        if (!map->is_barracks(barracks_pos)) {
            std::cout << "there is no barracks(\n";
            return;
        }
        
        Barracks* barracks = map->get_barracks(barracks_pos);
         
        if (!barracks->is_empty()) {
            std::cout << "busy already\n";
            return;
        }
        
        if (unit_name == "archer") {
            barracks->build_archer();
            return;
        }

        if (unit_name == "swordsman") {
            barracks->build_swordsman();
            return;
        }
        
        std::cout << "wrong name\n";
    }
};
