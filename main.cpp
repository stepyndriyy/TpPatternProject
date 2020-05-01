#include "src/map/map.h"
#include "src/player/player.h"
#include<iostream>
#include<vector>
#include<string>

void game_loop(const std::vector<Player> &players) {
    std::string action_type;    
    int current_player = 0;
    while (true) {
        std::cin >> action_type;
        if (action_type == "place") { 
            Cell cell;
            std::cin >> cell;
            std::cin >> unit_type;
            map.place(cell, )
        }    
    
    }

}


int main() {
    Player pl1("player1");
    Player pl2("player2");
    std::vector<Player> players = {pl1, pl2}
    map.print();
    return 0;
}
