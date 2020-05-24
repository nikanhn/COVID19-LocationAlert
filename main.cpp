#include <iostream>
#include <cmath>
#include "position.h"
#include "person.h"
using namespace std;
const int milesToFeet = 100;
const int socialDistanceInFeet=6;
struct City 
{
	int height;
	int width;
	int id;
};

City createCity(double areaInMile, int id)
{
	City city;
	city.height =floor(sqrt(areaInMile * milesToFeet)/socialDistanceInFeet);
	city.width =floor(sqrt(areaInMile* milesToFeet)/socialDistanceInFeet);
	city.id = id;
	return city;
}
int main()
{
	srand(time(0)); 
	City SanFrancisco = createCity(46.87,1);
	City SanJose = createCity(180.50,2);
	City Fremont = createCity(87.62,2);
	City Oakland = createCity(77.86,2);

	int choice;
	int numberOfPeople;
	int numberOfSickPeople;
	City Cities[4];
	Cities[0] = SanFrancisco;
	Cities[1] = Oakland;
	Cities[2] = Fremont;
	Cities[3] = SanJose;

	cout<<"Please enter 0 for SmallCity, 1 for MediumCity, 2 for LargCity, and 3 for ExtraLargeCity "<<endl;
	cin>> choice;
	if(cin.fail())
	{
		cout<< "Please enter a valid option!"<<endl;
	}
	else if (choice > 3)
	{
		cout<< "Please enter a valid option!"<<endl;
	}
	City ChosenCity= Cities[choice];

	cout<<"Please enter the number of people you want to be in the simulation, the maximum is: " << (ChosenCity.height*ChosenCity.width)/2<<endl;

	cin>> numberOfPeople;

	cout<<"Please enter the number of sick people you want to be in the simulation the maximum is: " << numberOfPeople/2<<endl;

	cin>> numberOfSickPeople;
	int original_ratio=floor((numberOfSickPeople*100)/numberOfPeople);
	Person* PersonList = new Person[numberOfPeople];
	
	for(int i=0; i<numberOfPeople;i++)
	{
		int x = floor(rand()%ChosenCity.width)+1;
		int y = floor(rand()%ChosenCity.height)+1;
		Position position = Position(x,y);
		bool isSick=false;
		if(i<numberOfSickPeople)
			{
			isSick=true;
			}

		int errorRate=30;

		PersonList[i]= Person(position,errorRate,isSick);
	}
	Person* PersonListRandom = new Person[numberOfPeople];
	for(int i=0;i<numberOfPeople;i++)
	PersonListRandom[i]=PersonList[i];
	Person* PersonListWise = new Person[numberOfPeople];
	for(int i=0;i<numberOfPeople;i++)
	PersonListWise[i]=PersonList[i];
	Person* PersonListSemiWise = new Person[numberOfPeople];
	for(int i=0;i<numberOfPeople;i++)
	PersonListSemiWise[i]=PersonList[i];
//starting simulation without the alarming near the sick people 
	int randomMoveCycles=0;
	numberOfSickPeople=0;
	while(floor((numberOfSickPeople*100)/numberOfPeople)<original_ratio+10 && randomMoveCycles<2147483647)
	{
		numberOfSickPeople=0;
		for(int i=0; i<numberOfPeople; i++)
		{
			//Position Check=PersonListRandom[i].position;
			PersonListRandom[i].isSick=PersonListRandom[i].updateHealth(PersonListRandom,i,numberOfPeople);
			PersonListRandom[i].randomMove(ChosenCity.height,ChosenCity.width,0,0);
			//if(Check.x==PersonListRandom[i].position.x && Check.y==PersonListRandom[i].position.y)
			//cout<<i<<"doesn't move"<<endl;
			if(PersonListRandom[i].isSick==true)	
			{
				numberOfSickPeople++;
			}
		}
		randomMoveCycles++;
	}
	int wiseMoveCycles=0;
	numberOfSickPeople=0;
	while(floor((numberOfSickPeople*100)/numberOfPeople)< original_ratio+10  && wiseMoveCycles<2147483647)
	{
		numberOfSickPeople=0;
		for(int i=0; i<numberOfPeople; i++)
		{
			
			PersonListWise[i].isSick=PersonListWise[i].updateHealth(PersonListWise,i,numberOfPeople);
			PersonListWise[i].wiseMove(ChosenCity.height,ChosenCity.width,0,0,PersonListWise,i,numberOfPeople);
			if(PersonListWise[i].isSick==true)
				numberOfSickPeople++;
		}
		wiseMoveCycles++;
		
	}
	int semiWiseMoveCycles=0;
	numberOfSickPeople=0;
	while(floor((numberOfSickPeople*100)/numberOfPeople)< original_ratio+10 && semiWiseMoveCycles<2147483647)
	{
		numberOfSickPeople=0;
		for(int i=0; i<numberOfPeople; i++)
		{
			PersonListSemiWise[i].isSick=PersonListSemiWise[i].updateHealth(PersonListSemiWise,i,numberOfPeople);
			if(floor(rand()%100)<PersonList[i].errorRate)
				PersonList[i].randomMove(ChosenCity.height,ChosenCity.width,0,0);
			else
				PersonListSemiWise[i].wiseMove(ChosenCity.height,ChosenCity.width,0,0,PersonListSemiWise,i,numberOfPeople);
				if(PersonListSemiWise[i].isSick==true)
					numberOfSickPeople++;
		}
		semiWiseMoveCycles++;

	}	
	cout<<"so there is three simulations, if people move randomly the spread out cycles will be : " << randomMoveCycles<<endl;
	cout<<"if people move wisely the spread out cycles will be : " << wiseMoveCycles<<endl;
	cout<<"if people move semi wisely with random error rates the spread out cycles will be : " << semiWiseMoveCycles<<endl;
return 0;
}
