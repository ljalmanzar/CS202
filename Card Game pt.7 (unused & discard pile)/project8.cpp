// include files
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "classes.h"

// Consts
// Structs

// Function Prototypes
int showMenu ();
void readDeck (card*); // should take in unshuffled deck 
player* readPlayers (int&); // int is the number of players
void swapCards (card&, card&);
void shuffleDeck (card*, card*); // takes shuffled first then unshuffled
void dealDeck (player*, card*, card*, card*, int); // takes players, shuffled, stock, discard, and number of players 
void printDeck (card*);
void showPlayers (player*, int); // int is for number of players

// main
int main()
{
	//variables
	int command;
	bool quit = false;
	char holdscreen;
	int numOfPlayers;
	
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
   
	// random seeding
   srand (time(NULL));
	
	system ("clear");
	
	// read in deck
		// function: readDeck
		readDeck(unshuffledptr);
	
	// read in players
		// function: readPlayers
		playerptr = readPlayers(numOfPlayers);
		playerhome = playerptr;
		
	// In Game Loop
	do
		{
			// show menu
				// function: showMenu
				command = showMenu();
			
			if (command == 1)
				{	
					// shuffle the deck
						// function: shuffleDeck
		         	shuffleDeck (shuffledptr, unshuffledptr);
				}
			else if (command == 2)
				{
					// deal the deck
						// function: dealDeck
						dealDeck (playerptr, shuffledptr, stockptr, discardptr, numOfPlayers);
				}
			else if (command == 3)
				{
					// show the unshuffled deck
						// function: printDeck
						printDeck (unshuffledptr);
				}
			else if (command == 4)
				{
					// show the shuffled deck
						// function: printDeck
						printDeck (shuffledptr);
				}
			else if (command == 5)
				{
					// show the stock and discard
						// function: printDeck
						cout << "---Stock---" << endl;
						printDeck (stockptr);
						cout << endl << "---Discard---" << endl << endl;
						printDeck (discardptr);
				}
			else if (command == 6)
				{
					// show players
						// function: showPlayers
						showPlayers(playerptr, numOfPlayers);
				}
			else if (command == 7)
				{
					// quit game
					quit = true;
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
	
delete [] playerhome;
delete [] discardhome;
delete [] stockhome;
delete [] shuffledhome;
delete [] unshuffledhome;
   
return 0;
}

// function implementation
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
    cout << "5) Show stock and discard piles" << endl;
    cout << "6) Show Players + ID #'s" << endl << endl;
    cout << "7) Quit" << endl << endl;

    cout << "Enter 1-7: ";
    cin >> input;
    cout << endl;

    return input; 
}

void readDeck (card* unshuffled)
{
	// variables
	string filename;
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
   fin.open(filename.c_str());
   
   for (ndx = 0; ndx < 52; ndx++)
   	{
			fin >> unshuffled[ndx];
			unshuffled[ndx].setLocation("Unshuffled");
   	}
   	
   // close file
   fin.close();
}

player* readPlayers (int& numOfPlayers)
{
	// variables
	string filename;
	ifstream fin;
	int ndx;
	
	player* pptr = NULL;
	
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
   fin.open(filename.c_str());
   
   // allocate the memory for # of players
   pptr = new player [numOfPlayers];
   
   for (ndx = 0; ndx < numOfPlayers; ndx++)
   	{
   		fin >> pptr[ndx];
   	}
   	
   fin.close();
   
   return pptr;
}

void swapCards (card& one, card& two)
{
	card temp;
	
	temp = one;
	one = two;
	two = temp;
}

void shuffleDeck (card* shuffled, card* unshuffled)
{
	int ndx, rand1, rand2;
	
	// copy the cards from unshuffled to shuffled
	for (ndx=0; ndx < 52; ndx++)
		{
			shuffled[ndx] = unshuffled[ndx];
			shuffled[ndx].setLocation("Shuffled");
		}
		
	// swap the cards within the shuffled multiple times
	for (ndx=0; ndx < 500; ndx++)
		{
			rand1 = rand() % 52;
			rand2 = rand() % 52;
			
			swapCards (shuffled[rand1],shuffled[rand2]);
		}
}

void dealDeck (player* plyr, card* shuffled, card* stock, card* discard, int numOfPlayers)
{
	//variables
	int mdx = 0, ndx = 0, plyrNdx = 0, handNdx=1;
	int excess;
	string temp;
	
	// deal to the plyrs
	for (mdx = 0; mdx < 5; mdx++)
		{
			for (plyrNdx = 0; plyrNdx < numOfPlayers; plyrNdx++)
				{
					temp = plyr[plyrNdx].getName();
					(plyr[plyrNdx]).setCard(shuffled[ndx],handNdx,temp);
					ndx++;
				}	
			handNdx ++;
		}
	// deal to the stock
	excess = 52 - (numOfPlayers*5);
	
	for (mdx = 0; mdx < (excess-1);mdx++)
		{
			stock[mdx] = shuffled[ndx];
			stock[mdx].setLocation("Stock");
			ndx++;
		}

	// deal to the discard
	discard[0] = shuffled[ndx]; 
	discard[0].setLocation("Discard");
}

void printDeck (card* deck)
{
	int rnk;
	
	for (int ndx = 0; ndx < 52; ndx ++)
		{
			rnk = deck[ndx].getRank();
			if (rnk != 0)
				{
					cout << deck[ndx] << endl;
				}
		}
}

void showPlayers (player* plyr, int n)
{
	for (int ndx = 0; ndx < n; ndx++)
		{
			cout << plyr[ndx];
			cout << endl << endl;
		}
}
