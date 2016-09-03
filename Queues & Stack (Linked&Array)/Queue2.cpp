#include <iostream>
#include <cstdlib>
#include <string>

#include "Queue.h"

using namespace std;

Queue::Queue(int i)
{
	max = i;
	front = 0;
	rear = -1;
	
	data = new int [max];
}

Queue::Queue(const Queue& s)
{
	max = s.max;
	front = s.front;
	rear = s.rear;
	
	data = new int [max];	
	for (int ndx=front; ndx<=rear; ndx++)
		{
			data[ndx] = s.data[ndx];
		}
}

Queue::~Queue()
{
	delete[] data;
	data = NULL;
}

Queue& Queue::operator=(const Queue& s)
{
	max = s.max;
	front = s.front;
	rear = s.rear;
	
	delete[] data;
	data = new int [max];	
	
	for (int ndx=front; ndx<=rear; ndx++)
		{
			data[ndx] = s.data[ndx];
		}
}

bool Queue::enqueue(int i)
{
	if (full())
		{	
			return false;
		}
	else
		{
			rear = (rear+1)%max;
			data[rear] = i;
			
			return true;
		}
}

bool Queue::dequeue(int& i)
{
	if (empty())
		{
			return false;
		}
	else
		{
			i = data[front];
			front = (front+1)%max;
				if (front == rear+1)
					{
						front = 0;
						rear = -1;
					}
			return true;
		}
}

bool Queue::empty() const
{
	if (rear==-1)
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool Queue::full() const
{
	if (rear == -1)
		{
			return false;
		}
		
	int cfront, crear;
	
	cfront = (front+1)%max;
	crear = (rear+1)%max;
	
	if ((cfront-crear) == 1)
		{
			return true;
		}
	else
		{
			return false;
		} 
}

bool Queue::clear()
{
	rear = -1;
}

bool Queue::operator==(const Queue& s) const
{
	bool test = true;
	
	if (max == s.max && front == s.front && rear == s.rear)
		{
			for (int ndx = front; ndx <= rear; ndx++)
				{
					if (data[ndx] != s.data[ndx])
						{
							test = false;
						}
				}
			
			return (test);
		}
	else
		{
			return false;
		}
}

ostream& operator<<(ostream& cout, const Queue& s)
{
/*	for (int ndx = s.front; ndx <= s.rear; ndx++)
		{
			cout << s.data[ndx] << " ";
		}
*/
		int ndx;
		for (ndx = 0; ndx < s.max; ndx++)
			{
				cout << s.data[ndx] << " ";		
			}
}
