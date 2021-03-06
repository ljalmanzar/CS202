// header files
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

// global constants

// structs 
struct card
   {
    char suit [10]; // default "suit"
    int rank; // default "0"
    char location [25]; // default "location"
   };

// function prototypes
void strcpy (char* destination, const char* source);

// main program
int main ()
{
      card unshuffled[52];
      card* unshuffledptr = unshuffled;
      card shuffled[52];
      card* shuffledptr = shuffled;
      
      
      cin >> (*unshuffledptr).suit >> (*unshuffledptr).rank >> (*unshuffledptr).location;
      
      strcpy ((*shuffledptr).suit ,(*unshuffledptr).suit);
      (*shuffledptr).rank = (*unshuffledptr).rank;
      strcpy ((*shuffledptr).location , "Given Location");
      
      cout << (*shuffledptr).suit << (*shuffledptr).rank << (*shuffledptr).location;
      
   return 0;
}

// function implementation
void strcpy (char *destination, const char *source)
{
	// variables
        int ndx = 0;

	// copy
	while (source[ndx] != '\0')
	   {
            destination[ndx] = source[ndx];
            ndx++;
	   }

    // add null
    destination[ndx] = '\0';
}
