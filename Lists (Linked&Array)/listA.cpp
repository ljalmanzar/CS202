#include <iostream>
#include <cstdlib>
#include <string>

#include "listA.h"
using namespace std;

List::List(int i)
{
	data = new char [i];
	size = i;
	actual = 0;
	cursor = -1;
}

List::List(const List& s)
{
	size = s.size;
	data = new char [size];
	
	actual = s.actual;
	cursor = s.cursor;
	
	int ndx = 0;
	while (ndx < actual)
		{
			data[ndx] = s.data[ndx];
			ndx++;
		}
}

List::~List()
{
	cout << endl;
	//delete[] data;
}

bool List::gotoBeginning()
{
	if (actual == 0)	
		{
			return false;
		}
		
		cursor = 0;
		return true;
}

bool List::gotoEnd()
{
	if (actual == 0)
		{
			return false;
		}
		
		cursor = size - 1;
		return true;

}

bool List::gotoNext()
{
	if (cursor == (size-1) || actual == 0)
		{
			return false;
		}
		
		cursor++;
		return true;
}

bool List::gotoPrior()
{
	if (cursor <= 0)
		{
			return false;
		}
	
	cursor --;
	return true;
}

bool List::insertAfter(char i)
{
	if (actual == size)
		{
			return false;
		}

	if (cursor == actual - 1)
		{
			cursor++;
			data[cursor] = i;
			
			actual++;
			
			return true;
		}
		
		int ndx = actual - 1;
		while (ndx > cursor)
			{
				data[ndx+1] = data[ndx];
				ndx--;
			}
			
		cursor++;
		actual++;
		data[cursor] = i;
		
		return true;

}

bool List::insertBefore(char i)
{
	if ((actual == 0) || (actual == 1) || (actual == size))
		{
			return false;
		}
	
		int ndx = actual - 1;
		while (ndx >= cursor)
			{
				data[ndx+1] = data[ndx];
				ndx--;
			}

		actual++;
		data[cursor] = i;
		
		return true;
	
}

bool List::remove(char& o)
{
	if (actual == 0)
		{
			return false;
		}
		
		o = data[cursor];

		// if removes last element, set cursor to beginning
		if (cursor == (actual-1))
			{
				cursor = 0;
			}
		
		for (int ndx = cursor; ndx <actual-1; ndx++)
			{
				data[ndx] = data[ndx+1];
			}
		actual--;
		
		if (actual == 0)
			{
				cursor = -1;
			}
				
		return true;
}

bool List::replace(char i)
{
	if (actual == 0)
		{
			return false;
		}
		
	data[cursor] = i;
	return true;
}

bool List::getCursor(char& o) const
{
	if (actual == 0)
		{
			return false;
		}
	
	o = data[cursor];
	return false;
}

bool List::empty() const
{
	if (actual == 0)
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
		if (actual == size)
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool List::clear()
{
	actual = 0;
	cursor = -1;
	return true;
}

List& List::operator=(const List& s)
{
	if (size != s.size)
		{
			delete[] data;
			size = s.size;
			data = new char [size];
		}
	actual = s.actual;
	cursor = s.cursor;
	
	int ndx = 0;
	while (ndx < actual)
		{
			data[ndx] = s.data[ndx];
			ndx++;
		}
}

ostream& operator<<(ostream& cout, const List& l)
{
	int ndx = 0;
	
	while (ndx<(l.actual))
		{
			cout << l.data[ndx] << " ";
			ndx++;
		}
		
	cout << endl; 
	cout << "Cursor= " << l.data[l.cursor];
}

bool List::operator==(const List& s) const
{
	bool check = true;
	int ndx = 0;
	
	if ((size == s.size) && (actual == s.actual))
		{
			while (ndx < actual && check == true)
				{
					if (data[ndx] != s.data[ndx])
						{
							check = false;
						}
					
					ndx++;
				}
				
			return check;
		}
		
	return false;
}
