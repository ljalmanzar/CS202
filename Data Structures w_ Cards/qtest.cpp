#include <iostream>
#include "classes.cpp"
using namespace std;

int main ()
{
	Queue <card> myq;
	card testcard;
	
	myq.enqueue(testcard);
	myq.dequeue(testcard);
	myq.empty();
	myq.full();
	myq.clear();
		myq.enqueue(testcard);
	myq.print();
	
	return 0;
}


