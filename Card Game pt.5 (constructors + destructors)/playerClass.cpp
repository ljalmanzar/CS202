/*************************************/
/*    Player Class Implementation    */
/*************************************/

#include <iostream>
#include <cstdlib>
#include "playerClass.h"
#include "stringFuncs.h"

using namespace std;

player::player()
{
	name = new char [25];
	ID = new int [5];
}
		
char* player::getName()
{
	return name;
}

void  player::setName(const char* string)
{
	strcpy (name, string);
}

int* player::getID()
{
	return ID;
}
		
void player::setID(int* id)
{
	int* home;
	home = ID;
	
	for (int ndx = 0; ndx < 5; ndx ++)
		{
			*ID = *id;
			ID ++;
			id ++;
		}
		
	ID = home;
}

void player::printPlayer()
{
	int ndx;
	int* home;
	home = ID;
	
	cout << name << " ";
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			cout << *ID;
			ID++;
		}
	
	ID = home;
}
		
player::~player()
{
	delete[] ID;
	delete[] name;
}
