#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h> 
#include "position.h"
using namespace std;

Position::Position()
{
    
}
Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}
int Position::get_distance(Position second)
{
   int result = 0;
   result = ceil(sqrt (pow(x- second.x,2)+ pow(y-second.y,2)));
   return result;
}
void Position::move_up(int heightMax)
{
    if(y+1 >= heightMax)
    {
        y = heightMax;
    }
    else
    {
        y++;
    }
}
void Position::move_down(int heightMin)
{   
    if(y-1<=  heightMin)
    {
        y =  heightMin;
    }
    else
    {
        y--;
    }
}
void Position::move_right(int widthMax)
{
    if(x + 1>= widthMax)
    {
        x = widthMax; 
    }
    else 
    {
		x++;
    }
}
void Position::move_left(int widthMin)
{
    if(x - 1<= widthMin)
    {
        x = widthMin;
    }
    else
    {
		x--;
	}
}

