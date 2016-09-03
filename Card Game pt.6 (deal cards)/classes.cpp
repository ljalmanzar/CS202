#include <iostream>
#include "classes.h"

using namespace std;

// String Implementations

bool strcmp (char* stringOne, char* stringTwo)
{
	while (*stringOne == *stringTwo)
		{
			stringOne ++;
			stringTwo ++;
			
			if (*stringOne == '\0' && *stringTwo == '\0')
				{
					return true;
				}
		}
}

void strcat (char* firstString, char* secondString)
{
	// variables

    // find spot to start
    while (*firstString != '\0')
       {
	      firstString ++;
	    }

    *firstString = ' ';
    firstString ++;

	// copy
	while (*secondString != '\0')
	   {
          *firstString = *secondString;
          firstString ++;
          secondString ++;
	   }

    // add null
    *firstString = '\0';
}

void strcpy (char* destination, const char* source)
{
	while( *source != '\0' )
		 {
		 	*destination = *source;
		 	destination++, source++;
		 }
		 
	*destination = '\0';
}

int strlen (char* string)
{
   int counter = 0;
   
	while (*string != '\0')
	   {
	      counter++;
	      string ++;
	   }
	  
	return counter;
}

//**** CARD IMPLEMENTATION ****//

card::card()
{
	suit = new char [8];
   strcpy(suit, "suit");

	rank = 0;
		
	location = new char [25];
   strcpy(location, "location");	
}

card::card(char* s, int rnk, char* l)
{
	suit = new char [8];
   strcpy(suit, s);

	rank = rnk;
		
	location = new char [25];
   strcpy(location, l);
}

card::card(const card &source)
{
	suit = new char [8];
   strcpy(suit, source.suit);
   
   rank = source.rank;
   
	location = new char [25];
   strcpy(location, source.location);	   	
}

const char* card:: getSuit() const
{
	return suit;
}

void card::setSuit(const char* string)
{
	strcpy(suit, string);
}

int card::getRank() const
{
	return rank;
}

void card::setRank(int number)
{
	rank = number;
}

const char* card:: getLocation() const
{
	return location;
}

void card::setLocation(const char* string)
{
	strcpy(location, string);
}
			
void card::printCard() const
{
	cout << suit << " " << rank << " " << location;
}
			
void card::copyCard (const card& source)
{
	strcpy (suit, source.suit);
	rank = source.rank;
	strcpy (location, source.location);
}
			
card::~card()
{
	delete[] suit;
	delete[] location;
}

//**** Player Implementation ****//

player::player()
{
	name = new char [25];
	ID = new int [5];
	hand = new card [5];
}
		
const char* player::getName() const 
{
	return name;
}

void  player::setName(const char* string)
{
	strcpy (name, string);
}

const int* player::getID() const
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

card* player::getHand() const
{
	return hand;
}

void player::setHand(card* s)
{
	int ndx;
	card* handhome;
	handhome = hand;
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			(*hand).copyCard(*s);
			hand++;
			s++;
		}
	
	hand = handhome;
}

void player::printPlayer()
{
	int ndx;
	int* idhome;
	idhome = ID;
	card* handhome;
	handhome = hand;
	
	cout << name << " ";
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			cout << *ID;
			ID++;
		}
	
	ID = idhome;
	
	cout << " ";
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			(*hand).printCard();
			cout << " ";
			hand++;
		}
	
	hand = handhome;
}
		
player::~player()
{
	delete[] hand;
	delete[] ID;
	delete[] name;
}
