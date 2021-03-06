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
	for (int ndx=0; ndx<max; ndx++)
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
	for (int ndx=0; ndx<max; ndx++)
		{
			data[ndx] = s.data[ndx];
		}
}

bool Queue::enqueue(int i)
{
	if (rear == (max-1))
		{
			return false;
		}
	else
		{ 
			rear++;
			data[rear] = i;
			return true;
		}
}

bool Queue::dequeue(int& i)
{
	if (rear == -1)
		{
			return false;
		}
	else
		{	
			i = data[front];
	
			for (int ndx=0; ndx<rear; ndx++)
				{
					data[ndx] = data[ndx+1];
				}
		
			rear--;
		}
}

bool Queue::empty() const
{
	if (rear == -1)
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
	if (rear == (max-1))
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
			for (int ndx = 0; ndx <= rear; ndx++)
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
	for (int ndx = 0; ndx <= s.rear; ndx++)
		{
			cout << s.data[ndx] << " ";
		}
}
