#pragma once
#include<vector>
#include<set>
#include<iostream>
#include "src/map/gamemap.h"
#include "src/player/player.h"
#include "src/units/units"
#include "src/commands/commands"
#include "src/buildings/barracks"

class Game {
private:
    GameMap* map = GameMap::get_instance();

    std::vector<Player> players;
    
    bool add_unit(int player_num, const Cell &pos, Entity* unit); 
    
    void update_player(int player_num); 
public:
    Game();

    void game_loop();
};



void Game::update_player(int player_num) {
    for (int y = 0; y < map->get_size(); ++y) {
        for (int x = 0; x < map->get_size(); ++x) {
            Entity* entity = map->get_entity(Cell(x, y));
            if (entity == nullptr)
                continue;
            if (entity->get_player_id() != players[player_num].get_player_id()) {
                continue;
            }
            
            if (Barracks *b = dynamic_cast<Barracks*>(entity)) {
                BarracksAdapted adapted(b, Cell(x, y));
                adapted.update();
                continue;
            }
            entity->update();
        }
    }  
}    

bool Game::add_unit(int player_num, const Cell &pos, Entity* unit) {
    if (!map->is_cell_empty(pos)) {
        return false;
    }
    map->set_cell(pos, unit);
    return true;
}

Game::Game() {
        
    players.push_back( Player("player1"));
    players.push_back(Player("Player2"));

    int sz = map->get_size();
    add_unit(0, Cell(1, 1), new Swordsman(1));
    add_unit(1, Cell(sz - 2, sz - 2), new Swordsman(2)); 
    add_unit(0, Cell(0, 0), new Barracks(1));
    add_unit(1, Cell(sz - 1, sz - 1), new Barracks(2));
}


void Game::game_loop() {
    std::string action_type;    
    int current_player = 0;
    int x, y;
    while (true) {
        update_player(current_player); 
        map->print(); 
        std::cin >> action_type;
        while (action_type != "end") {
            if (action_type == "move") {
                std::cin >> y >> x;
                CommandMoveUnit cmd(players[current_player], Cell(x, y));
                cmd.execute(); 
            }

            else if (action_type == "attack") {
                std::cin >> y >> x;
                CommandAttack cmd(players[current_player], Cell(x, y));
                cmd.execute();
            }

            else if (action_type == "barracks") {
                std::cin >> y >> x;
                CommandBarracks cmd(players[current_player], Cell(x, y));
                cmd.execute(); 
            } 

            else {
                std::cout << "wrong command\n";
            }
            
            std::cin >> action_type;
        }

        current_player = (current_player + 1) % players.size(); 
        
        std::cout << players[current_player].get_player_name() << " turn\n";
    }

}
