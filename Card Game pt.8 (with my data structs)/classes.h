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
	
class List;

class Node
{
	private:
		Node(card,Node*);
		card data;
		Node* next;
		friend class List;
      friend ostream& operator<<(ostream&, const List&);
};

class List{
   public:
      List(int = 0);
      List(const List&);
		~List();
		bool gotoBeginning();
		bool gotoEnd();
		bool gotoNext();
      bool gotoPrior();
		bool insertAfter(card);
		bool insertBefore(card);
      bool remove(card&);
		bool replace(card);
		bool getCursor(card&) const;
      bool empty() const;
      bool full() const;
      bool clear();
		List& operator=(const List&);
      friend ostream& operator<<(ostream&, const List&);
                
   private:
		Node* head;
		Node* cursor;
};

template <typename T>
class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack&);
                ~Stack();
                Stack<T>& operator=(const Stack&);
                bool push(T);
                bool pop(T&);
                bool empty() const;
                bool full() const;
                bool clear();
                void print() const;
        private:
                int max;
                int top;
                int actual;
                T* data;
};

template <typename R>
class Queue;

template <typename K>
class node
{
	private:
		node(K,node<K>*);
		K data;
		node<K>* next;
		friend class Queue<K>;
};

template <typename R>
class Queue{
	public:
               Queue(int = 10);
               Queue(const Queue&);
               ~Queue();
               Queue& operator=(const Queue&);
               bool enqueue(R);
               bool dequeue(R&);
               bool empty() const;
               bool full() const;
               bool clear();
               void print();
   private:
               int max;
               node<R>* front;
               node<R>* rear;
};
