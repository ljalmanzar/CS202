#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class card
	{
		public:
			card();
			// suit, rank, location
			card(string, int, string);
			card(const card &);
			
			const string getSuit() const;
			void setSuit(const string);
			int getRank() const;
			void setRank(int number);
			const string getLocation() const;
			void setLocation(const string);
			
			card& operator=(const card&);
			bool operator>(const card&);
			
			friend bool operator<(const card&, const card&);
			friend ifstream& operator>>(ifstream&, card&);
			friend ostream& operator<<(ostream&, card&);
			
			~card();
			
		private:
			string suit; // default "suit"
			int rank; // default "0"
			string location; // default "location"	
	};
	
class player
	{
		public:
		player();
		
		const string getName() const;
		void setName(const string);
		const int* getID() const;
		void setID(int*);
		card* getHand() const;
		void setHand(card*);
		void setCard(card, int, string);
		
		friend ifstream& operator>>(ifstream&, player&);
		friend ostream& operator<<(ostream&, player&);
		
		~player();
		
		private:
		string name;
		int* ID;
		card* hand;
	};
