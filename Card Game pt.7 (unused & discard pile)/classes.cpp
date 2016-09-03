#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "classes.h"

using namespace std;

//**** CARD IMPLEMENTATION ****//

card::card()
{
	suit = "suit";
	rank = 0;
   location = "location";
}

card::card(string s, int rnk, string l)
{
	suit = s;
	rank = rnk;
	location = l;
}

card::card(const card &source)
{
	suit = source.suit; 
   rank = source.rank;  
	location = source.location;   	
}

const string card:: getSuit() const
{
	return suit;
}

void card::setSuit(const string s)
{
	suit = s;
}

int card::getRank() const
{
	return rank;
}

void card::setRank(int number)
{
	rank = number;
}

const string card:: getLocation() const
{
	return location;
}

void card::setLocation(const string l)
{
	location = l;
}
	
card& card::operator=(const card& c)
{
	if (this != &c)
		{
			suit = c.suit;
			rank = c.rank;
			location = c.location;
		}
	return *this;
}		

bool card::operator>(const card& c)
{
	if (rank > c.rank)
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool operator<(const card& one, const card& two)
{
	if (one.rank < two.rank)
		{
			return true;
		}
	else
		{
			return false;
		}
}	

ifstream& operator>>(ifstream& fin, card& c)
{
	fin >> c.suit >> c.rank;
}

ostream& operator<<(ostream& cout, card& c)
{
	cout << c.suit << " " << c.rank << " " << c.location;
}
			
card::~card()
{
}

//**** Player Implementation ****//

player::player()
{
	name = "name";
	ID = new int [5];
	hand = new card [5];
}
		
const string player::getName() const 
{
	return name;
}

void player::setName(const string n)
{
	name = n;
}

const int* player::getID() const
{
	return ID;
}
		
void player::setID(int* id)
{
	for (int ndx = 0; ndx < 5; ndx ++)
		{
			ID[ndx] = id[ndx];
		}
}

card* player::getHand() const
{
	return hand;
}

void player::setHand(card* s)
{
	for (int ndx = 0; ndx < 5; ndx++)
		{
			hand[ndx] = s[ndx];
		}
}

void player::setCard(card s, int n, string loc)
{
	hand[n-1] = s;
	hand[n-1].setLocation(loc);
}

ifstream& operator>>(ifstream& fin, player& p)
{
	int ndx;
	char temp;
	
	fin >> p.name;
	
	for (ndx = 0; ndx < 5; ndx ++)
		{
			fin >> temp;
			p.ID[ndx] = temp - '0';
		}
}

ostream& operator<<(ostream& cout, player& p)
{
	int ndx;
	int rnk;
	
	cout << p.name << " ";
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			cout << p.ID[ndx];
		}
	
	cout << endl;
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			rnk = (p.hand[ndx]).getRank();
			
			if (rnk != 0)
				{
					cout << p.hand[ndx] << " ";
				}
			else
				{
					cout << "No Card" << " ";
				}
		}
}		
player::~player()
{
	delete[] hand;
	delete[] ID;
}
