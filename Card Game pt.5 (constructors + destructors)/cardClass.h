/*************************************/
/*            Card Class             */
/*************************************/

#include <iostream>
#include <cstdlib>

class card
	{
		public:
			card(char* s = NULL, int rnk = 0, char* l = NULL);
			
			char* getSuit();
			void setSuit(const char* string);
			int getRank();
			void setRank(int number);
			char* getLocation();
			void setLocation(const char* string);
			
			void printCard();
			
			void copyCard (const card& source);
			
			~card();
			
		private:
			char* suit; // default "suit"
			int rank; // default "0"
			char* location; // default "location"	
	};
