#pragma once
#include "map.h"

class IPathFinding {
public:
    virtual int find_distance(const Cell &from, const Cell &to)=0;
};
