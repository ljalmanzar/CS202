#include <iostream>
#include <cstdlib>
#include <string>

#include "Stack.h"

using namespace std;

template <typename T>
Stack<T>::Stack(int i)
{
	max = i;
	top = -1;
	data = new T [max];
}

template <typename T>
Stack<T>::Stack(const Stack& s)
{
	max = s.max;
	top = s.top;
	
	data = new T [max];
	
	for (int ndx=0; ndx<max; ndx++)
		{
			data[ndx] = s.data[ndx];
		}
}

template <typename T>
Stack<T>::~Stack()
{
	//delete[] data;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& s)
{
	max = s.max;
	top = s.top;
	
	delete[] data;
	data = new T [max];
	
	for (int ndx=0; ndx<=top; ndx++)
		{
			data[ndx] = s.data[ndx];
		}
}

template <typename T>
bool Stack<T>::push(T s)
{
	int ndx;
	
	if ((top+1) == max)
		{
			return false;
		}
	else
		{
			top++;
		}
	
	data[top] = s;
	
	return true;
}

template <typename T>
bool Stack<T>::pop(T& s)
{

	if (top == -1)
		{
			return false;
		}
	else
		{
			s = data[top];
			top--;
		}
		
	return true;
}

template <typename T>
bool Stack<T>::empty() const
{
	if (top == -1)
		{
			return true;
		}
	else
		{
			return false;
		}
	
}

template <typename T>
bool Stack<T>::full() const
{
	if ((top+1) == max)
		{
			return true;
		}
	else
		{
			return false;
		}
}

template <typename T>
bool Stack<T>::clear()
{
	top = -1;
	
	return true;
}

template <typename T>
void Stack<T>::print () const
{
	for (int ndx = top; ndx >= 0 ; ndx--)
		{
			cout << data[ndx] << " ";
		}
}
