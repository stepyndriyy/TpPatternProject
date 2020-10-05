#pragma once
#include "ipath.h"
#include "gamemap.h"

class DefaultPathFinding : public IPathFinding {
public:
    virtual int find_distance(const Cell &from, const Cell &to) override {
        GameMap* map = GameMap::get_instance();
        int MAP_SIZE = map->get_size();
        using std::vector;
        vector<vector<int> > dist(MAP_SIZE, vector<int> (MAP_SIZE, -1));
        std::queue<Cell> queue;
        queue.push(from);
        dist[from.y][from.x] = 0;
        while (!queue.empty()) {
            Cell cur = queue.front();
            queue.pop();
            for (Cell diff : {Cell(1, 0), Cell(0, 1), Cell(-1, 0), Cell(0, -1)}) {
                Cell next = cur + diff;
                if (!map->is_in_bound(next))
                    continue;
                if (dist[next.y][next.x] != -1 || !map->is_cell_empty(next))
                    continue;
                dist[next.y][next.x] = dist[cur.y][cur.x] + 1;
                queue.push(next); 
            }   
        }
        return dist[to.y][to.x];  
    }
};
