#include <iostream>
#include <cstdlib>
#include <string>

//#include "Queue.h"
#include "Queue.h"

using namespace std;

int main()
{
	int one, two;
	bool empty;
	
	Stack test;
	
/*	empty = test.enqueue(9.87);
	cout << empty;
	test.enqueue(10);
	
	cout << test;
	
	cout << endl << endl;
	
	test.dequeue(one);
	
	test.dequeue(two);
	
	cout << one << " " << two << " ";
	
	cout << test;
	
	cout << endl << endl;
*/	
	test.push(5);
	
	test.push(6);

	test.print();
	
	//test.clear();
	
	empty = test.full();
	
	cout << "HERE = " << empty;
	test.print();
	
	cout << endl << endl;

return 0;
}


