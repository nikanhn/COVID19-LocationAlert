#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "position.h"
class Person 
{
    public:
    Position position;
    int errorRate;
    bool isSick;
    Person();
    Person(Position position, int errorRate, bool isSick);
    void randomMove(int heightMax, int widthMax, int heightMin, int widthMin);
    void wiseMove(int heightMax, int widthMax, int heightMin, int widthMin, Person* People, int id , int size);
    bool updateHealth(Person* People,int id, int size);
};
#endif
