#include "src/map/gamemap.h"
#include "src/player/player.h"
#include "src/units/swordman.h"
#include "src/units/archer.h"
#include "src/commands/command.h"
#include<iostream>
#include<vector>
#include<string>

void game_loop(const std::vector<Player> &players, GameMap &map) {
    map.print();
    std::string action_type;    
    int current_player = 0;
    while (true) {
        std::cin >> action_type;
        while (action_type != "end") {
            if (action_type == "move") {
                int x, y;
                std::cin >> y >> x;
                CommandMoveUnit cmd(map, players[current_player], Cell(x, y));
                cmd.execute(); 
            }


            std::cin >> action_type;
        }
        current_player = (current_player + 1) % players.size(); 
        
        std::cout << "next turn\n";
        // to do
        //std::cout << players[current_player].get_player_name() << " turn\n";
    }

}

int main() {
    Player pl1("player1");
    Player pl2("player2");
    std::vector<Player> players = {pl1, pl2};
    GameMap map;
    
    //testing
    map.set_cell(Cell(0,0), new Swordsman(1));
    map.set_cell(Cell(20,20), new Swordsman(2));
    // __---
    

    game_loop(players, map);

    return 0;
}
