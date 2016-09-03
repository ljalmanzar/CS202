/* String Operations */
#include <iostream>
#include "stringfuncs.h"

using namespace std;

// Function Implementations

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
