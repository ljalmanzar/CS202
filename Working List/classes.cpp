#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "classes.h"

using namespace std;

//**** CARD IMPLEMENTATION ****//

card::card()
{
	suit = "suit";
	rank = 0;
   location = "location";
}

card::card(string s, int rnk, string l)
{
	suit = s;
	rank = rnk;
	location = l;
}

card::card(const card &source)
{
	suit = source.suit; 
   rank = source.rank;  
	location = source.location;   	
}

const string card:: getSuit() const
{
	return suit;
}

void card::setSuit(const string s)
{
	suit = s;
}

int card::getRank() const
{
	return rank;
}

void card::setRank(int number)
{
	rank = number;
}

const string card:: getLocation() const
{
	return location;
}

void card::setLocation(const string l)
{
	location = l;
}
	
card& card::operator=(const card& c)
{
	if (this != &c)
		{
			suit = c.suit;
			rank = c.rank;
			location = c.location;
		}
	return *this;
}		

bool card::operator>(const card& c)
{
	if (rank > c.rank)
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool operator<(const card& one, const card& two)
{
	if (one.rank < two.rank)
		{
			return true;
		}
	else
		{
			return false;
		}
}	

ifstream& operator>>(ifstream& fin, card& c)
{
	fin >> c.suit >> c.rank;
}

ostream& operator<<(ostream& cout, card& c)
{
	cout << c.suit << " " << c.rank << " " << c.location;
}
			
card::~card()
{
}

//**** Player Implementation ****//

player::player()
{
	name = "name";
	ID = new int [5];
	hand = new card [5];
}
		
const string player::getName() const 
{
	return name;
}

void player::setName(const string n)
{
	name = n;
}

const int* player::getID() const
{
	return ID;
}
		
void player::setID(int* id)
{
	for (int ndx = 0; ndx < 5; ndx ++)
		{
			ID[ndx] = id[ndx];
		}
}

card* player::getHand() const
{
	return hand;
}

void player::setHand(card* s)
{
	for (int ndx = 0; ndx < 5; ndx++)
		{
			hand[ndx] = s[ndx];
		}
}

void player::setCard(card s, int n, string loc)
{
	hand[n-1] = s;
	hand[n-1].setLocation(loc);
}

ifstream& operator>>(ifstream& fin, player& p)
{
	int ndx;
	char temp;
	
	fin >> p.name;
	
	for (ndx = 0; ndx < 5; ndx ++)
		{
			fin >> temp;
			p.ID[ndx] = temp - '0';
		}
}

ostream& operator<<(ostream& cout, player& p)
{
	int ndx;
	int rnk;
	
	cout << p.name << " ";
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			cout << p.ID[ndx];
		}
	
	cout << endl;
	
	for (ndx = 0; ndx < 5; ndx++)
		{
			rnk = (p.hand[ndx]).getRank();
			
			if (rnk != 0)
				{
					cout << p.hand[ndx] << " ";
				}
			else
				{
					cout << "No Card" << " ";
				}
		}
}		
player::~player()
{
	delete[] hand;
	delete[] ID;
}


//**************** LIST IMPLEMENTATIONS *****************//
Node::Node(card i, Node* l)
{
	data = i;
	next = l;
}


List::List(int i)
{
	head = NULL;
	cursor = NULL;
}

List::List(const List& s)
{
	Node* null = NULL;
	Node* source = s.head;
		if (source != NULL)
			{
				while(source->next!=NULL)
					{
						if (head == NULL)
							{
								head = new Node(source->data, null);
								cursor =	head;
							}
						
						cursor->next = new Node(source->data, null);
						
						cursor = cursor->next;
						source = source->next;
					}
			}
}

List::~List()
{
	if (head != NULL)
		{
			Node* temp;
	
			while (head->next != NULL)
				{
					temp = head->next;
					delete head;
					head = temp;
				}
		
			delete head;
			head = cursor = NULL;
		}
}

bool List::gotoBeginning()
{
	if (head == NULL)
		{
			return false;
		}
	
	cursor = head;
	return true;
}

bool List::gotoEnd()
{
	if (head == NULL)
		{
			return false;
		}
		
	while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
	return true;
}

bool List::gotoNext()
{
	if (cursor == NULL || cursor->next == NULL)
		{
			return false;
		}
		
	cursor = cursor -> next;
	return true;
}

bool List::gotoPrior()
{
	if (cursor == head)
		{
			return false;
		}
		
	Node* temp = head; 
	
	while (temp->next != cursor)
		{
			temp = temp->next;
		}
		
	cursor = temp;
	temp = NULL;
	
	return true;
}

bool List::insertAfter(card i)
{
	if (head == NULL)
		{
			head = new Node(i,head);
			cursor = head;
			cursor->next = NULL;
			return true;
		}
	if (cursor->next == NULL)
		{
			cursor->next = new Node(i,head);
			cursor = cursor->next;
			cursor->next = NULL;
			return true;
		}
		
	Node* temp = new Node(i,cursor->next);
	cursor->next = temp;
	cursor = cursor->next;
	return true;
}

bool List::insertBefore(card i)
{
	if (cursor == head)
		{
			return false;
		}
		
	gotoPrior();
	
	Node* temp = new Node(i,cursor->next);
	cursor->next = temp;
	cursor = cursor->next;
	return true;	
}

bool List::remove(card& o)
{
	if (cursor == NULL)
		{
			return false;
		}
	else if (head->next == NULL)
		{
			o = cursor->data;
			delete cursor;
			
			head = cursor = NULL;
		}
	else if (cursor->next == NULL)
		{
			Node* temp = cursor;
			
			o = cursor->data;
			
			cursor = head;
			delete temp;
			temp = NULL;
			
			return true;
		}
	else
		{
			Node* temp = cursor;
	
			o = cursor->data;

			gotoPrior();
			cursor->next = temp->next;
			delete temp;
			temp = NULL;
	
			return true;
		}
}

bool List::replace(card i)
{
	if (cursor == NULL)
		{
			return false;
		}
		
	cursor->data = i;
	return true;
}

bool List::getCursor(card& o) const
{
	if (cursor == NULL)
		{
			return false;
		}
		
	o = cursor->data;
	return true;
}

bool List::empty() const
{
	if (head == NULL)
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool List::full() const
{
	return false;
}

bool List::clear()
{
	if (head != NULL)
		{
			Node* temp;
	
			while (head->next != NULL)
				{
					temp = head->next;
					delete head;
					head = temp;
				}
		
			delete head;
			head = cursor = NULL;
	
			return true;
		}
}

List& List::operator=(const List& s)
{
	Node* temp = NULL;
	
	cursor = head;
	Node* source = s.head;
	
	while (cursor->next!=NULL || source->next!=NULL)
		{
			cursor->data = source->data;
			cursor=cursor->next;
			source=source->next;
		}
		
	cursor->data = source->data;
	
	if (cursor->next==NULL && source->next==NULL)
		{
			return (*this);
		}
	if (cursor->next==NULL)
		{
			while (source->next!=NULL)
				{
					source=source->next;
					cursor->next=new Node(source->data,temp);
					cursor=cursor->next;
				}
			cursor = head;
		
			return (*this);
		}
		
	if (source->next==NULL)
		{
			while (cursor->next != NULL)
				{
					temp = cursor->next;
					delete cursor;
					cursor = temp;
				}
			delete cursor;
			cursor = head;
			
			return (*this);
		}
}

ostream& operator<<(ostream& cout, const List& l)
{
	if (l.head!=NULL)
		{
			Node* temp = l.head;

					while (temp->next != NULL)
						{
							cout << temp->data << " ";
							temp = temp->next;
						}
					cout << temp->data;
		}	
	return cout;
}
