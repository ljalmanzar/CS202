// include files
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "stringFuncs.h"
#include "cardClass.h"
#include "playerClass.h"

using namespace std;
   
// global constants

// function prototypes
int showMenu ();
void getDeck (card* unshuffledptr);
player* getNames(int &numOfPlayers);
void swapCards (card* one, card* two);
void shuffleDeck (card* unshuffledptr, card* shuffledptr);
void dealCards(card* shuffled, card* stock, card* discard);
void showDeck (card* deck);
void showPlayers (player* plyr, int numOfPlayers);

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
   
   player* playerptr = NULL;
   player* playerhome = NULL;
      
	int command;
	bool quit = false;
	char holdscreen;
	
	int numOfPlayers;
	
	// random seeding
   srand (time(NULL));
	
	// get the cards
	getDeck (unshuffledptr);
	
	// get players
	playerptr = getNames (numOfPlayers);
	playerhome = playerptr;
	
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
         		//dealDeck 
         		dealCards(shuffledptr, stockptr, discardptr);
         	}
         else if (command == 3)
            {
		          // print the unshuffled deck
		          // function : showDeck
					 showDeck (unshuffledptr);
            }
         else if (command == 4)
            {
		          // print the shuffled deck
		          // function : showDeck
		          showDeck (shuffledptr);
            }
         else if (command == 5)
            {
               // show players
               // function : showPlayers
               showPlayers (playerptr, numOfPlayers);
            }  
         else if (command == 6)
            {
              // set quit to true
              quit = true;
            }
         else if (command == 7)
            {
		          // print the stock deck
		          // function : showDeck
		          showDeck(stockptr);
            }
         else if (command == 8)
            {
		          // print the discard deck
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
	
	delete[] playerhome;
	delete[] discardhome;
	delete[] stockhome;
	delete[] shuffledhome;
	delete[] unshuffledhome;
		
	return 0;
}

// function implementations
int showMenu ()
{
    int input = 0;
    cout << "**************" << endl;
    cout << "*CRAZY EIGHTS*" << endl;
    cout << "**************" << endl << endl;
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
   int tempRank;
      
   ifstream fin;
   int ndx = 0;
   
   // title
   cout << "**************" << endl;
   cout << "*CRAZY EIGHTS*" << endl;
   cout << "**************" << endl << endl;
   
   // get file name
   cout << "Enter deck file name: "; 
   cin >> filename;
   cout << endl;
   
   // open file
   fin.clear();
   fin.open(filename);
   
   for (ndx = 0; ndx < 52; ndx++)
      {
			// get the suit and copy it
			fin >> tempSuit;	
			(*unshuffledptr).setSuit(tempSuit);
			
			// get the rank and copy it
			fin >> tempRank;
			(*unshuffledptr).setRank(tempRank);
			
			// set location
			(*unshuffledptr).setLocation("Unshuffled");
			
			// show card (testing purposes)
			// (*unshuffledptr).printCard();		
				
			// increment
			unshuffledptr++;
      }
   
   // delete necessary
   delete[] tempSuithome;
   delete[] filenamehome;
   
   // close file
   fin.close();
}

player* getNames(int &numOfPlayers)
{
	char* tempname = new char[15];
   char* tempnamehome = tempname;
   char* filename = new char[10];
   char* filenamehome = filename;
   int * tempid = new int[5];
   int* tempidhome = tempid;
   
   char temp;
   
   ifstream fin;
   
   int ndx = 0;
   int idndx = 0;
   
   player* plyrptr = NULL; 
   player* plyrhome = NULL;
   
   // ask for file and players
   cout << "Enter player name file: ";
   cin >> filename;
   cout << endl;
   
   do 
   	{
			cout << "How many players (2-8) will be playing? ";
			cin >> numOfPlayers;
   	}
   while (numOfPlayers < 2 || numOfPlayers > 8);
   	
   // open file
   fin.clear();
   fin.open(filename);
   
   // allocate the memory for # of players
   plyrptr = new player [numOfPlayers];
   plyrhome = plyrptr;	
   
   for (ndx = 0; ndx < numOfPlayers; ndx++)
   	{
			// get name and insert 
			fin >> tempname;
			(*plyrptr).setName(tempname);
		
			// get ID and insert
				for (idndx = 0; idndx < 5; idndx ++)
				   {
				   	fin >> temp;
				   	*tempid = temp - '0';

						tempid++;
				   }
				   
			(*plyrptr).setID(tempidhome); 	
			tempid = tempidhome;
			
			// show player (testing)
			// (*plyrptr).printPlayer();
			
			plyrptr++;
   	}
   	
   delete[]tempnamehome;
   delete[]filenamehome;
   delete[]tempidhome;
   
   return plyrhome;  
}

void swapCards (card* one, card* two)
{
	card temp;
	
	temp.copyCard (*one);
	(*one).copyCard (*two);
	(*two).copyCard (temp);
}

void shuffleDeck (card* unshuffledptr, card* shuffledptr)
{
	int ndx;
	int indx;
	int randOne;
	int randTwo;
	char temp;
	
	card* sptr = shuffledptr;
	card* secondsptr = shuffledptr;
	
	for (ndx = 0; ndx < 52; ndx++)
		{
			(*shuffledptr).copyCard(*unshuffledptr);
			(*shuffledptr).setLocation("Shuffled");
			shuffledptr++;
			unshuffledptr++;
		}

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
     
   cout << endl << "****DONE****" << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );
}

void dealCards(card* shuffled, card* stock, card* discard)
{
	int ndx;
	char temp;
	
	for (ndx = 0; ndx < 51; ndx++)
		{
			(*stock).copyCard(*shuffled);
			(*stock).setLocation("Stock");
			
			stock++;
			shuffled++;
		}
	
	(*discard).copyCard(*shuffled);
	(*discard).setLocation("Discard");
	
   cout << endl << "****DONE****" << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );
}

void showDeck (card* deck)
{
	char temp;
	
	int checker;
	for (int ndx = 0; ndx < 52; ndx++)
		{
			checker = (*deck).getRank(); 
			if ( checker != 0)
				{
					(*deck).printCard();
					cout << endl;
				}
			deck++;
		}
		
	cout << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );
}

void showPlayers (player* plyr, int numOfPlayers)
{
	char temp;
	
	for (int ndx = 0; ndx < numOfPlayers; ndx++)
		{
			(*plyr).printPlayer();
			cout << endl;
			plyr++;
		}
		
	cout << endl;
   cout << "Type 'C' and enter to return to menu... ";
   cin >> temp;
   cout << endl;

   system ( "clear" );
}
