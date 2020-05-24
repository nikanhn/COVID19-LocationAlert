#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
class Position 
{    
    public:
    double x;
    double y;
    Position();
    Position(int x, int y);
    int get_distance(Position second);
    void move_up(int heightMax);
    void move_down(int heightMin);
    void move_right(int widthMax);
    void move_left(int widthMin);
};
#endif
