#pragma once
#include <vector>
#include <string>

class GameMap { 
private:
    const unsigned TURNS_COUNT;
    const unsigned PLAYERS_COUNT;
    const unsigned BASE_DEFENSE = 2;
    std::vector<std::string> cells_type;
    std::vector<std::vector<unsigned> > graph;
public:
    GameMap(char *inp_file);

    unsigned getNear(unsigned vert);
    std::string getType(unsigned vert);
    unsigned getCellDeffend(unsigned vert);      
};