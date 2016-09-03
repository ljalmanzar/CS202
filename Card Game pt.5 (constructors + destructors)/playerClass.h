/*************************************/
/*          Player Class             */
/*************************************/

#include <iostream>
#include <cstdlib>

class player
	{
		public:
		player();
		
		char* getName();
		void setName(const char* string);
		int* getID();
		void setID(int* id);
		void printPlayer();
		
		~player();
		
		private:
		char* name;
		int* ID;
	};
