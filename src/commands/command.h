#pragma once
#include<iostream>
#include<string>
#include<map>
#include "src/map/gamemap"
#include "src/interface/entity.h"

class Command {
protected:
    GameMap* map = GameMap::get_instance();
    Player *player;
    Command(Player &pl) : player(&pl) {}

public:
    virtual void execute() = 0;     

};



class CommandBarracks : public Command {
private:
    Cell barracks_pos;
public:
    CommandBarracks(Player &pl, const Cell &c) : Command(pl), barracks_pos(c) {}

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
        std::string unit_name;
        std::cin >> unit_name;
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
