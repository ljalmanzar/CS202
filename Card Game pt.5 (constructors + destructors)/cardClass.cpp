/*************************************/
/*     Card Class Implementation     */
/*************************************/

#include <iostream>
#include <cstdlib>
#include "cardClass.h"
#include "stringFuncs.h"

using namespace std;

card::card(char* s, int rnk, char* l)
{
	if (s == NULL)
      {
	      suit = new char [8];
	      strcpy(suit, "Suit");
	   }
   else 
      {
         strcpy(suit, s);
      }

	rank = rnk;
		
   if (l == NULL)
      {
	      location = new char [25];
	      strcpy(location, "Location");
      }
   else
      {
         strcpy(location, l);
      }
}

char* card::getSuit()
{
	return suit;
}

void card::setSuit(const char* string)
{
	strcpy(suit, string);
}

int card::getRank()
{
	return rank;
}

void card::setRank(int number)
{
	rank = number;
}

char* card::getLocation()
{
	return location;
}

void card::setLocation(const char* string)
{
	strcpy(location, string);
}
			
void card::printCard()
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

