#include <iostream>
#include <cstdlib>

bool strcmp (char* stringOne, char* stringTwo);

void strcat (char* firstString, char* secondString);

void strcpy (char* destination, const char* source);

int strlen (char* string);

class card
	{
		public:
			card();
			card(char* s, int rnk, char* l);
			card(const card &source);
			
			const char* getSuit() const;
			void setSuit(const char* string);
			int getRank() const;
			void setRank(int number);
			const char* getLocation() const;
			void setLocation(const char* string);
			
			void printCard() const;
			
			void copyCard (const card& source);
			
			~card();
			
		private:
			char* suit; // default "suit"
			int rank; // default "0"
			char* location; // default "location"	
	};
	
class player
	{
		public:
		player();
		
		const char* getName() const;
		void setName(const char* string);
		const int* getID() const;
		void setID(int* id);
		card* getHand() const;
		void setHand(card* s);
		void printPlayer();
		
		~player();
		
		private:
		char* name;
		int* ID;
		card* hand;
	};
