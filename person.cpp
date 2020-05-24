#include <iostream>
#include <cstdlib>
#include <stdlib.h> 
#include "person.h"

Person::Person()
{
	
}
Person::Person(Position position, int errorRate, bool isSick)
{
	this->errorRate = errorRate;
	this->isSick = isSick;
	this->position = position;
}
void Person::randomMove(int heightMax, int widthMax, int heightMin, int widthMin)
{
	int randomTest = rand () % 4 +1;
	switch (randomTest)
	{
		case 1:
			position.move_up(heightMax);
		break;
		case 2:
			position.move_down(heightMin);
		break;
		case 3:
			position.move_right(widthMax);
		break;
		case 4:
			position.move_left(widthMin);
		break; 
	}
}
void Person::wiseMove(int heightMax, int widthMax, int heightMin, int widthMin, Person* People, int id , int size)
{
	int falseMoves[4]={0,0,0,0};
	int fmIndex=0;
	for(int i=0; i<size; i++)
	{
	    if(i ==id)
	    continue;
      	    if(fmIndex==4)
 	    break;
	    Person another = People[i];
	    if(this->position.get_distance(another.position)==1)
	    {
			if((this->position.x-another.position.x)==0)
			{
				if((this->position.y - another.position.y)<0)
				{
					falseMoves[fmIndex]=1;
					fmIndex++;
				}
				else
				{
					falseMoves[fmIndex]=2;
					fmIndex++;
				}
			}
			else
			{
				if((this->position.x - another.position.x)<0)
				{
					falseMoves[fmIndex]=3;
					fmIndex++;
				}
				else
				{
					falseMoves[fmIndex]=4;
					fmIndex++;
				}		
			}
	    }
	}
	if(fmIndex==4)
	return;		
	int randomTest = rand () % 4 +1;
	bool exist=false;
	  for(int j=0; j<fmIndex;j++)
	  {
		if(randomTest==falseMoves[j])
		exist=true;
	  }
	  while(exist)
	  {
	  randomTest = rand () % 4 +1;
	  for(int j=0; j<fmIndex;j++)
	  {
		if(randomTest==falseMoves[j])
		exist=true;
		else
		exist=false;
	  }
	  }
	switch (randomTest)
	{
		case 1:
			position.move_up(heightMax);
		break;
		case 2:
			position.move_down(heightMin);
		break;
			case 3:
			position.move_right(widthMax);
		break;
		case 4:
			position.move_left(widthMin);
		break; 
	}	
}
bool Person::updateHealth(Person* People,int id, int size)
{
    if(this->isSick==true)
    return true;
    for(int i=0; i<size; i++)
    {
    	if(i ==id)
    	continue;
    	Person another = People[i];
    	if(this->position.get_distance(another.position)==0)
    	{
        	if(another.isSick==true)
        	{
        	if(this->isSick==false)
        	{
        	//cout<<"Person with id : "<<id<<"got sick"<<endl;
        	}
		 this->isSick == true;
		 return true;		
		}
    	}
    }
    return false;
}

