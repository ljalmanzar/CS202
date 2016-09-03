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
    char* suit; // default "suit"
    int rank; // default "0"
    char* location; // default "location"
   };
   
struct player 
   {
    char* name;
    int ID;
   };

// function prototypes
int showMenu ();
void getDeck (card* unshuffledptr);
player* getNames (int &players);
void shuffleDeck (card* unshuffledptr, card* shuffledptr);
void showDeck (card* deckptr);
void showPlayers (player* plyrptr, int numOfPlayers);
void mystrcpy (char* destination, const char* source);
int strlen (char* string);
void copyCard (card* destinationDeck, card* sourceDeck, const char* newLocation);
void swapCards (card* cardOne, card* cardTwo);

// main program
int main()
{
      // variables 
      card* unshuffledptr = new card [52];
      card* unshuffledhome = unshuffledptr; 
      card* shuffledptr = new card [52];
      card* shuffledhome = shuffledptr;
      
      player* plyrptr = NULL;
      player* plyrptrhome = NULL;

      int players = 0;
      bool quit = false;
      int command;
      char holdscreen;
      int ndx = 0;
      int length;
      
      // random seeding
      srand (time(NULL));

      // ask for files for deck and players
         // function : getFile
         getDeck(unshuffledptr);
         
      // allocate memory for shuffled deck
		for (ndx = 0; ndx < 52; ndx++)
			{
				// get suit size
				length = strlen ((*unshuffledptr).suit);
				// get memory
				(*shuffledptr).suit = new char [length];
				// get location size 
				length = strlen ((*unshuffledptr).location);
				// get memory
				(*shuffledptr).location = new char [length];
				
				unshuffledptr ++;
				shuffledptr ++;
			}
			
		// reset
		unshuffledptr = unshuffledhome;
		shuffledptr = shuffledhome;
			
      // function : getNames
      plyrptr = getNames(players);
      plyrptrhome = plyrptr;
         
      system ("clear");
      
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
               shuffleDeck (unshuffledptr, shuffledptr);
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
               showPlayers(plyrptr, players);
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

	// deallocate
	for (ndx = 0; ndx < players; ndx ++)
	   {
			delete[] (*plyrptr).name;
			plyrptr ++; 
		}		
	plyrptr = plyrptrhome;
	delete[] plyrptr; 
	
	shuffledptr = shuffledhome;
	for (ndx = 0; ndx < 52; ndx ++)
	   {
			delete[] (*shuffledptr).suit;
			delete[] (*shuffledptr).location;
			shuffledptr ++; 
		}
		
	unshuffledptr = unshuffledhome;
	for (ndx = 0; ndx < 52; ndx ++)
	   {
			delete[] (*unshuffledptr).suit;
			delete[] (*unshuffledptr).location;
			unshuffledptr ++; 
		}
		
	shuffledptr = shuffledhome;
	delete[] shuffledptr;
	
	unshuffledptr = unshuffledhome;
	delete[] unshuffledptr;	
	
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
void getDeck (card* unshuffledptr)
{
      char* filename = new char [10];
      char* filenamehome = filename;
      char* tempSuit = new char [10];
      char* tempSuithome = tempSuit; 
      
      int suitLen;
      ifstream fin;
      int ndx = 0;

   // get file name
   cout << "Enter deck file name: "; 
   cin >> filename;
   cout << endl;
   
   // open file
   fin.clear();
   fin.open(filename);
   
   for (ndx = 0; ndx < 52; ndx++)
      {
			// get the suit
			fin >> tempSuit;
		
			// get length the suit
			suitLen = strlen (tempSuit);
		
			// allocate the required size
			(*unshuffledptr).suit = new char [suitLen+1];
		
			// copy the suit into the new allocated area
			mystrcpy((*unshuffledptr).suit, tempSuit);
			
			// get the rank
			fin >> (*unshuffledptr).rank;
			
			// allocate space for location
			(*unshuffledptr).location = new char [12];
			
			// insert location
			mystrcpy ((*unshuffledptr).location, "Unshuffled");
			
			unshuffledptr++;
      }
   
   // delete necessary
   delete[] tempSuithome;
   delete[] filenamehome;
   
   // close file
   fin.close();
}
player* getNames (int &players)
{
   char* filename = new char[10];
   char* filenamehome = filename;
   char* tempname = new char[15];
   char* tempnamehome = tempname;
   
   ifstream fin;
   
   int ndx = 0;
   int nameSize;
   
   player* plyrptr = NULL; 
   player* plyrhome = NULL;
   
   // ask for file
   cout << "Enter player name file: ";
   cin >> filename;
   cout << endl;
   
   // open file
   fin.clear();
   fin.open(filename);
   
   // read in number of players
   fin >> players;
   
   // allocate the memory for # of players
   plyrptr = new player [players];
   plyrhome = plyrptr;
   
   // read in all names and IDs
   while (ndx < players)
      {
         // get name 
         fin >> tempname;
         
         // measure length 
         nameSize = strlen (tempname);

         // allocate it's memory
         (*plyrptr).name = new char[nameSize+1];
         
         // copy name to new allocated space
         mystrcpy ((*plyrptr).name, tempname);
         
         // get int 
         fin >> (*plyrptr).ID; 
         
         plyrptr++;
         ndx++;
      }
   
   //set back to home
   plyrptr = plyrhome;
   
   // delete
   delete[] tempnamehome;
   delete[] filenamehome;
   
   // close
   fin.close();
   
   return plyrhome;
}
void shuffleDeck (card* unshuffledptr, card* shuffledptr)
{
   // variables
	card* usptr = unshuffledptr;
	card* sptr = shuffledptr;
	card* secondsptr = sptr;
	int randOne, randTwo;
	
	int ndx;
	int indx;
	char temp;

	// copy the unshuffled deck to shuffled
	for (ndx = 0; ndx < 52; ndx ++)
	   {
			copyCard (shuffledptr, unshuffledptr, "Shuffled");
			shuffledptr ++;
			unshuffledptr ++;
	   }
	   
	// swap cards
	for (ndx = 0; ndx < 1000; ndx++)
	  {
	     randOne = rand() % 52;
	     randTwo = rand() % 52;
	     
	     for (indx = 0; indx != randOne; indx ++)
	        {
	           sptr ++;
	        }
	        
	     for (indx = 0; indx != randTwo; indx ++)
	        {
	           secondsptr ++;
	        }
	                
	  	  swapCards (sptr, secondsptr);
	  	  
	     for (indx = randOne; indx != 0; indx --)
	        {
	           sptr --;
	        }
	        
	     for (indx = randTwo; indx != 0; indx --)
	        {
	           secondsptr --;
	        }	  	  
     }
     
   // end prompt
   cout << "******DONE******" << endl;
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
void showPlayers (player* plyrptr, int numOfPlayers)
{
 int ndx = 0;
 char temp;
 
 for (ndx = 0; ndx < numOfPlayers; ndx++)
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
void mystrcpy (char* destination, const char* source)
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
void copyCard (card* destinationDeck, card* sourceDeck, const char* newLocation)
{
  // copy suit
  mystrcpy ((*destinationDeck).suit ,(*sourceDeck).suit);
  // copy rank
  (*destinationDeck).rank = (*sourceDeck).rank;
  // copy location
  mystrcpy ((*destinationDeck).location , newLocation);
}

void swapCards (card* cardOne, card* cardTwo)
{
  // variables
  card temp;
  card* tempCard = &temp;
  int length;

  // allocate memory to temp
  length = strlen ((*cardOne).suit);
  temp.suit = new char [length];
  char* suitHome = temp.suit;
  
  length = strlen ((*cardOne).location);
  temp.location = new char [length];
  char* locationHome = temp.location;
  
  // copy first to temp
  copyCard (tempCard, cardOne, (*cardOne).location);
  
  // copy second to first
  copyCard (cardOne, cardTwo, (*cardTwo).location);
  
  // copy temp to second
  copyCard (cardTwo, tempCard, (*tempCard).location);
  
  // delete
  delete[] locationHome;
  delete[] suitHome;
}
