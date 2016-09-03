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
    int* ID;
    card* hand;
   };

// function prototypes
int showMenu ();
void getDeck (card* unshuffledptr);
void allocateForDeck (card* deck);
void defaultDeck (card* deck);
player* getNames (int &players);
void shuffleDeck (card* unshuffledptr, card* shuffledptr);
void dealDeck (card* shuffledptr, player* player, card* stockptr, card* discardptr, int numOfPlayers);
void showDeck (card* deckptr);
void showPlayers (player* plyrptr, int numOfPlayers);
void strcpy (char* destination, const char* source);
int strlen (char* string);
void copyCard (card* destinationDeck, card* sourceDeck, const char* newLocation);
void swapCards (card* cardOne, card* cardTwo);
void deletePlayer (player* playerptr);
void deleteAllPlayers (player* playerptr, int numOfPlayers);
void deleteCard (card* deck);
void deleteDeck (card* deck);

// main program
int main()
{
      // variables 
      card* unshuffledptr = new card [52];
      card* unshuffledhome = unshuffledptr; 
      card* shuffledptr = new card [52];
      card* shuffledhome = shuffledptr;
      
      card* stockptr = new card [52];
      card* stockhome = stockptr; 
      card* discardptr = new card [52];
      card* discardhome = discardptr;
      
      player* plyrptr = NULL;
      player* plyrptrhome = NULL;

      int players = 0;
      bool quit = false;
      int command;
      char holdscreen;
      int ndx = 0;
      
      // random seeding
      srand (time(NULL));

		system ("clear");
		
      // ask for files for deck and players
         // function : getFile
         getDeck(unshuffledptr);
         
      // allocate memory for shuffled deck, stock, and discard
		//allocateForDeck (shuffledptr);
		//allocateForDeck (stockptr);
		//allocateForDeck (discardptr);
			
	for (ndx = 0; ndx < 52; ndx++)
		{
			// get memory
			(*shuffledptr).suit = new char [8];
			(*shuffledptr).location = new char [15];
			(*stockptr).suit = new char [8];
			(*stockptr).location = new char [15];
			(*discardptr).suit = new char [8];
			(*discardptr).location = new char [15];
							
			shuffledptr ++;
			stockptr ++;
			discardptr ++;
		}
		
		shuffledptr = shuffledhome;
		stockptr = stockhome;
		discardptr = discardhome;
		
		// default decks
		defaultDeck (shuffledptr);
		defaultDeck (stockptr);
		defaultDeck (discardptr);
		
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
         		dealDeck (shuffledptr, plyrptr, stockptr, discardptr, players);
         	}
         else if (command == 3)
            {
		          // print the unshuffled deck
		          // function : showDeck
                showDeck(unshuffledptr);
            }
         else if (command == 4)
            {
		          // print the shuffled deck
		          // function : showDeck
                showDeck(shuffledptr);
            }
         else if (command == 5)
            {
               // show players
               // function : showPlayers
               showPlayers(plyrptr, players);
            }  
         else if (command == 6)
            {
              // set quit to true
              quit = true;
            }
         else if (command == 7)
            {
		          // print the shuffled deck
		          // function : showDeck
                showDeck(stockptr);
            }
         else if (command == 8)
            {
		          // print the shuffled deck
		          // function : showDeck
                showDeck(discardptr);
            }
         else 
            {
              // error message and hold for user
              cout << endl;
              cout << "Incorrect Input, please hit any key to return to main menu..." << endl;
              cin >> holdscreen;
            }
    } 

	while (quit == false);     

showDeck (stockptr);
showDeck (discardptr);
	// deallocate
	plyrptr = plyrptrhome;
	deleteAllPlayers (plyrptr, players);
	delete[] plyrptr; 
	plyrptr = plyrptrhome = NULL;
	
	shuffledptr = shuffledhome;
	deleteDeck (shuffledptr);
	delete[] shuffledptr;
	shuffledptr = shuffledhome = NULL;
			
	unshuffledptr = unshuffledhome;
	deleteDeck (unshuffledptr);
	delete[] unshuffledptr;
	unshuffledptr = unshuffledhome = NULL;	
		
	return 0;
}

// function implementations
int showMenu ()
{
    int input = 0;
    cout << "Main Menu" << endl << endl;
    cout << "1) Shuffle Deck" << endl;
    cout << "2) Deal Cards" << endl;
    cout << "3) Print Unshuffled Deck on Screen" << endl;
    cout << "4) Print Shuffled Deck on Screen" << endl;
    cout << "5) Show Players + ID #'s" << endl;
    cout << "6) Quit" << endl << endl;
    cout << "7) Print the Stock Pile to the Screen" << endl;
    cout << "8) Print the Discard Pile to the Screen" << endl << endl;

    cout << "Enter 1-6: ";
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

			// allocate
			(*unshuffledptr).suit = new char [8];
		
			// copy the suit into the new allocated area
			strcpy((*unshuffledptr).suit, tempSuit);
			
			// get the rank
			fin >> (*unshuffledptr).rank;
			
			// allocate space for location
			(*unshuffledptr).location = new char [12];
			
			// insert location
			strcpy ((*unshuffledptr).location, "Unshuffled");
			
			unshuffledptr++;
      }
   
   // delete necessary
   delete[] tempSuithome;
   delete[] filenamehome;
   
   // close file
   fin.close();
}
void allocateForDeck (char* deck)
{
	int ndx;
/*	
	for (ndx = 0; ndx < 52; ndx++)
		{
			// get memory
			(*deck).suit = new char [8];
			(*deck).location = new char [11];
				
			deck ++;
		}
*/		
}
void defaultDeck (card* deck)
{
	int ndx;
	for (ndx = 0; ndx < 52; ndx++)
		{
			strcpy((*deck).suit, "suit");
			(*deck).rank = 0;
			strcpy((*deck).location, "location");
			deck++;
		}
}
player* getNames (int &players)
{
   char* tempname = new char[15];
   char* tempnamehome = tempname;
   char temp;
   
   ifstream fin;
   
   int ndx = 0;
   int idndx;
   int nameSize;
   
   player* plyrptr = NULL; 
   player* plyrhome = NULL;
   
   // ask for file and players
   cout << "Enter player name file: ";
   char* filename = new char[10];
   char* filenamehome = filename;
   cin >> filename;
   cout << endl;
   
   do 
   	{
			cout << "How many players (2-8) will be playing? ";
			cin >> players;
   	}
   while (players < 2 || players > 8);
   	
   // open file
   fin.clear();
   fin.open(filename);
   
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
         strcpy ((*plyrptr).name, tempname);
         
         // allocate memory for ID
         (*plyrptr).ID = new int [5];   
         
         // get ID
         for (idndx = 0; idndx < 5; idndx ++)
            {
            	fin >> temp;
            	*((*plyrptr).ID) = temp - '0';
   
            	(*plyrptr).ID ++;
            }
            
         cout << endl;
         
         // allocate for player hand
         (*plyrptr).hand = new card[5];   
         
         plyrptr++;
         ndx++;
      }
   
   //set back to home
   plyrptr = plyrhome;
   
   ndx = 0;
   while (ndx < players)
      { 
         for (idndx = 0; idndx < 5; idndx ++)
            {
            	(*plyrptr).ID --;
            }
            
         ndx++;
         plyrptr ++;
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
void dealDeck (card* shuffledptr, player* player, card* stockptr, card* discardptr, int numOfPlayers)
{
	int ndx;
	int playerNdx;
	int excessCards;
	char temp;
	
	// deal cards
	while (ndx < numOfPlayers)
		{
			for (playerNdx = 0; playerNdx < numOfPlayers; playerNdx++)
				{
					copyCard ((*player).hand, shuffledptr, (*player).name);
					// cout << *((*player).hand).suit << *((*player).hand).rank << *((*player).hand).location << endl;
					player ++;
					shuffledptr ++; 
				}
			
			for (playerNdx = numOfPlayers; playerNdx > 0; playerNdx--)
				{
					player --;
				}
				
			ndx ++;
		}
		
	excessCards = 52 - (numOfPlayers * 5); 
	
	// insert remainder of cards into the stock pile
	for (ndx = 0; ndx < (excessCards - 1); ndx++)
		{
			copyCard (stockptr, shuffledptr, "Stock");
			stockptr ++;
			shuffledptr ++;	
		}
		
	// insert last card into discard deck
	copyCard (discardptr, shuffledptr, "Discard");
	
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
      	if ( (*deckptr).rank != 0)
      		{
         		cout << (*deckptr).suit << " " << (*deckptr).rank << " " << (*deckptr).location << endl;
         	}
         	
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
	int* IDptr = (*plyrptr).ID;
	int ndx = 0;
	int idndx = 0;
	char temp;
 
	for (ndx = 0; ndx < numOfPlayers; ndx++)
		{
			IDptr = (*plyrptr).ID;
   	
			cout << (*plyrptr).name << " ";
      
         for (idndx = 0; idndx < 5; idndx ++)
            {
            	cout << *IDptr;
            	IDptr ++;
            }
            
			cout << endl;
			plyrptr++;
		}
   
	// reset
   
	cout << endl;
   cout << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );
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
void copyCard (card* destinationDeck, card* sourceDeck, const char* newLocation)
{
	// copy suit
	strcpy ((*destinationDeck).suit ,(*sourceDeck).suit);
	// copy rank
	(*destinationDeck).rank = (*sourceDeck).rank;
	// copy location
	strcpy ((*destinationDeck).location , newLocation);
}

void swapCards (card* cardOne, card* cardTwo)
{
	// variables
	card temp;
	card* tempCard = &temp;

	// allocate memory to temp
	temp.suit = new char [8];
 	char* suitHome = temp.suit;
  
	temp.location = new char [15];
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
void deletePlayer (player* playerptr)
{
	delete[] (*playerptr).name;
	delete[] (*playerptr).ID;
	delete[] (*playerptr).hand;
}
void deleteAllPlayers (player* playerptr, int numOfPlayers)
{
	int ndx;
	
	for (ndx = 0; ndx < numOfPlayers; ndx++)
		{
			deletePlayer (playerptr);
			playerptr ++;
		}
}
void deleteCard (card* deck)
{
	delete[] (*deck).suit;
	delete[] (*deck).location;
}
void deleteDeck (card* deck)
{
	int ndx;
	
	for (ndx = 0; ndx < 52; ndx ++)
	   {
			deleteCard (deck);
			deck ++; 
		}	
}
