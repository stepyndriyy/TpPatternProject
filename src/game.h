#pragma once
#include <sstream>
#include <stdexcept>
#include<vector>
#include<set>
#include<iostream>
#include "map/gamemap.h"
#include "player/player.h"
#include "units/units"
#include "commands/commands"
#include "buildings/barracks"

namespace strfunc {
    Cell string_to_cell(std::string &str) {
        std::size_t pos = 0, pos2 = 0;
        int y = -1, x = -1;
        try {
            y = std::stoi(str, &pos);
            x = std::stoi(str.substr(pos), &pos2);
        } catch (std::invalid_argument& _a) {
            return Cell(-1, -1);
        }
        str = str.substr(pos2 + pos);
        return Cell(x, y);
    }

    std::string split_first_word(std::string &str) {
        while (str.size() > 0 && str.back() == ' ')
            str.pop_back();
        while (str.size() > 0 && str[0] == ' ')
            str.erase(0, 1); 
        
        int n = str.find(" ");
        if (n == std::string::npos) {
            n = str.size();
        }
        std::string answer = str.substr(0, n);
        str = str.substr(n);
        
        return answer;
    }
}


class Game {
private:
    GameMap* map = GameMap::get_instance();

    std::vector<Player> players;
    
    bool add_unit(int player_num, const Cell &pos, Entity* unit); 
    
    int  update_player(int player_num); 
    
    bool check_winner();   
public:
    Game();

    void game_loop();
};



int Game::update_player(int player_num) {
    int count = 0;
    for (int y = 0; y < map->get_size(); ++y) {
        for (int x = 0; x < map->get_size(); ++x) {
            Entity* entity = map->get_entity(Cell(x, y));
            if (entity == nullptr)
                continue;
            if (entity->get_player_id() != players[player_num].get_player_id()) {
                continue;
            }
            count++;
            if (Barracks *b = dynamic_cast<Barracks*>(entity)) {
                BarracksAdapted adapted(b, Cell(x, y));
                adapted.update();
                continue;
            }
            entity->update();
        }
    }
    return count;
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
    add_unit(0, Cell(1, 1), new Swordsman(players[0].get_player_id()));
    add_unit(1, Cell(sz - 2, sz - 2), new Swordsman(players[1].get_player_id())); 
    add_unit(0, Cell(0, 0), new Barracks(players[0].get_player_id()));
    add_unit(1, Cell(sz - 1, sz - 1), new Barracks(players[1].get_player_id()));
}



bool Game::check_winner() {
    if (players.size() <= 1) {
        if (players.size() == 0) {
            std::cout << "DRAW!!\n";
        }
        if (players.size() == 1) {
            std::cout << players[0].get_player_name() << " WIN!!\n"; 
        }
        return true;
    }
    return false;
}


void Game::game_loop() {
    std::string action_type;    
    int current_player = 0;

    std::string inp; 
    while (true) {
        if (update_player(current_player) == 0) {
            players.erase(players.begin() + current_player);
            current_player %= players.size();
            std::cout << players[current_player].get_player_name() << " turn\n";
        }
        if (check_winner())
            break;     
        
        map->print(); 
        std::getline(std::cin, inp);
        action_type = strfunc::split_first_word(inp);
        while (action_type != "endturn") {
            
            if (action_type == "move") {
                Cell from, to;
                from = strfunc::string_to_cell(inp);
                to = strfunc::string_to_cell(inp); 
                CommandMoveUnit cmd(players[current_player], from, to);
                cmd.execute(); 
            }

            else if (action_type == "attack") {
                Cell from, to;
                from = strfunc::string_to_cell(inp);
                to = strfunc::string_to_cell(inp);
                CommandAttack cmd(players[current_player], from, to);
                cmd.execute();
            }

            else if (action_type == "barracks") {
                Cell from = strfunc::string_to_cell(inp);
                CommandBarracks cmd(players[current_player], from, strfunc::split_first_word(inp));
                cmd.execute(); 
            } 

            else {
                std::cout << "wrong command\n";
            }
            map->print();  
            std::getline(std::cin, inp); 
            action_type = strfunc::split_first_word(inp);
        }

        current_player = (current_player + 1) % players.size(); 
        
        std::cout << players[current_player].get_player_name() << " turn\n";
    }

}
