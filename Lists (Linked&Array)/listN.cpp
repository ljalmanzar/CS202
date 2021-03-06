#include <iostream>
#include <cstdlib>
#include <string>

#include "listN.h"
using namespace std;

Node::Node(char i, Node* l)
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

bool List::insertAfter(char i)
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

bool List::insertBefore(char i)
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

bool List::remove(char& o)
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

bool List::replace(char i)
{
	if (cursor == NULL)
		{
			return false;
		}
		
	cursor->data = i;
	return true;
}

bool List::getCursor(char& o) const
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

List& List::operator=(const List& s)
{
	//Node* cursorhold = s->cursor;
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
	Node* temp = l.head;

			while (temp->next != NULL)
				{
					cout << temp->data << " ";
					temp = temp->next;
				}
	
	return cout;
}

bool List::operator==(const List& s) const
{
}
