#pragma once
#include<iostream>
#include<string>
#include<map>
#include "../map/gamemap.h"
#include "../interface/entity.h"

class Command {
protected:
    GameMap* map = GameMap::get_instance();
    Player *player;
    Command(Player &pl) : player(&pl) {}

public:
    virtual void execute() = 0;     

};

