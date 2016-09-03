// include files
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
   
// global constants
const int suits = 4;
const int rank = 13;
const int stringSize = 50;
const int cards = 52;

// structs 
struct card
   {
    char suit [10]; // default "suit"
    int rank; // default "0"
    char location [25]; // default "location"
   };
   
struct player 
   {
    char name[30];
    int ID;
   };

// function prototypes
int showMenu ();
void getFile (card* unshuffledptr);
void getNames (player* plyrptr);
void shuffleDeck (card* unshuffledptr, card* shuffledptr);
void showDeck (card* deckptr);
void showPlayers (player* plyrptr);
void strcpy (char* destination, const char* source);
void copyCard (card* destinationDeck, card* sourceDeck, const char* newLocation);

// main program
int main()
   {
      // variables
      card unshuffled[52];
      card* unshuffledptr = unshuffled;
      card shuffled[52];
      card* shuffledptr = shuffled;
      
      player plyr[4];
      player* plyrptr = plyr;

      bool quit = false;
      int command;
      char holdscreen;
      int ndx = 0;
      
      // defaulting
      for (ndx = 0; ndx < 52; ndx++)
       {
         strcpy ((*unshuffledptr).suit, "suit");
         (*unshuffledptr).rank = 0;
         strcpy ((*unshuffledptr).location, "location");
         
         strcpy ((*shuffledptr).suit, "suit");
         (*shuffledptr).rank = 0;
         strcpy ((*shuffledptr).location, "location");

         unshuffledptr++;
         shuffledptr++;
       }
      
      unshuffledptr = unshuffled;
      shuffledptr = shuffled;
       
      ndx = 0; 
      for (ndx = 0; ndx < 4; ndx++)
       {
         strcpy ((*plyrptr).name, "name");
         (*plyrptr).ID = 0;
         
         plyrptr++;
       }
       
      plyrptr = plyr;
       
      // random seeding
      srand (time(NULL));

      // ask for files for deck and players
         // function : getFile
         getFile(unshuffledptr);
         
         // function : getNames
         getNames(plyrptr);
         
  // main game loop          
  do 
    {
         // show menu 
         // function : showMenu
         command = showMenu();

         // check user command
         if (command == 1)
            {
		         // shuffle the cards
		         // function : shuffleDeck
               shuffleDeck (unshuffled, shuffled);
            }
         else if (command == 2)
            {
		          // print the unshuffled deck
		          // function : showDeck
                showDeck(unshuffledptr);
            }
         else if (command == 3)
            {
		          // print the shuffled deck
		          // function : showDeck
                showDeck(shuffledptr);
            }
         else if (command == 4)
            {
               // show players
               // function : showPlayers
               showPlayers(plyrptr);
            }  
         else if (command == 5)
            {
              // set quit to true
              quit = true;
            }
         else 
            {
              // error message and hold for user
              cout << endl;
              cout << "Incorrect Input, please hit any key to go back to menu again..." << endl;
              cin >> holdscreen;
            }
    } 

  while (quit == false);     

   return 0;
   }

// function implementations
int showMenu ()
{
    int input = 0;
    cout << "Main Menu" << endl << endl;
    cout << "1) Shuffle Deck" << endl;
    cout << "2) Print Unshuffled Deck on Screen" << endl;
    cout << "3) Print Shuffled Deck on Screen" << endl;
    cout << "4) Show Players + ID #'s" << endl;
    cout << "5) Quit" << endl << endl;

    cout << "Enter 1-5: ";
    cin >> input;
    cout << endl;

    return input; 
}
void getFile (card* unshuffledptr)
{
      char filename [10];
      ifstream fin;
      int ndx = 0;

   // get file name
   cout << "Enter deck file name: "; 
   cin >> filename;
   cout << endl;
   
   // open file
   fin.clear();
   fin.open(filename);
   
   // prime loop
   fin >> (*unshuffledptr).suit;
   fin >> (*unshuffledptr).rank;
   strcpy ((*unshuffledptr).location, "unshuffled");
   unshuffledptr ++;
   ndx ++;
   
   // read in all values
   for (ndx = 1; ndx < 52; ndx ++)
      {
         fin >> (*unshuffledptr).suit >> (*unshuffledptr).rank;
         strcpy ((*unshuffledptr).location, "unshuffled");
         // cout << (*unshuffledptr).suit << " " << (*unshuffledptr).rank << endl;
         
         unshuffledptr ++;
      }
   
   // close file
   fin.close();
}
void getNames (player* plyrptr)
{
   char filename[10];
   ifstream fin;
   int ndx = 0;
   
   // ask for file
   cout << "Enter player name file: ";
   cin >> filename;
   cout << endl;
   
   // open file
   fin.clear();
   fin.open(filename);
   
   // prime loop
   fin >> (*plyrptr).name;
   fin >> (*plyrptr).ID;
   plyrptr++;
   ndx ++;
   
   // read in all names and IDs
   while (ndx < 4)
      {
         fin >> (*plyrptr).name;
         fin >> (*plyrptr).ID;
         // cout << (*plyrptr).name << " " << (*plyrptr).ID << endl;
         plyrptr ++;
         ndx++;
      }
   
   // close
   fin.close();
}
void shuffleDeck (card* unshuffledptr, card* shuffledptr)
{
    // variables
    int counterNdx = 0; 
    int ndx = 0;
    int randomNum;
    char temp;
    char checker [52];
    char* checkerptr = checker;

    // clear checker index
    for (counterNdx = 0; counterNdx < 52; counterNdx++)
       {
        *checkerptr = 'G';
        checkerptr ++;
       }
   
    // get random int, check the checker array, if good
      // use that spot in shuffled array, if not skip and repeat
      while (ndx < 52)
        {
          randomNum = rand() % 52;
        
          for (counterNdx=0; counterNdx != randomNum; counterNdx++)
            {
              checkerptr ++;
              shuffledptr ++;
            }

          if ((*checkerptr) == 'G')
            {
              copyCard (shuffledptr, unshuffledptr, "Shuffled");
              unshuffledptr++;
              ndx ++;
              
              (*checkerptr) = 'F';
            }
           
          checkerptr = checker;
          for (counterNdx = randomNum; counterNdx != 0; counterNdx--)
            {
              shuffledptr --;
            }
        }

   // end prompt
   cout << endl;
   cout << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );

}
void showDeck (card* deckptr)
{
   int ndx;
   char temp;
   
   for (ndx = 0; ndx < 52; ndx++)
      {
         cout << (*deckptr).suit << " " << (*deckptr).rank << " " << (*deckptr).location << endl;
         deckptr++;
      }

   cout << endl;
   cout << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );

}
void showPlayers (player* plyrptr)
{
 int ndx = 0;
 char temp;
 
 for (ndx = 0; ndx < 4; ndx++)
   {
      cout << (*plyrptr).name << " " << (*plyrptr).ID << endl;
      plyrptr++;
   }
   
   cout << endl;
   cout << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );
}
void strcpy (char* destination, const char* source)
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
void copyCard (card* destinationDeck, card* sourceDeck, const char* newLocation)
{
  // copy suit
  strcpy ((*destinationDeck).suit ,(*sourceDeck).suit);
  // copy rank
  (*destinationDeck).rank = (*sourceDeck).rank;
  // copy location
  strcpy ((*destinationDeck).location , newLocation);
}
