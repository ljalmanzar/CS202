#include "classes.h"
#include <iostream>

using namespace std;

int main() {

	bool test;
	List l(10);
	card grab;
	card mycard("DIAMONDS", 10, "JAYZ");
	card newcard("NIGGER", 25, "YE");
	
	l.insertAfter(mycard);
	cout << l;
	l.insertAfter(newcard);
	l.insertAfter(mycard);
	l.insertAfter(mycard);
	l.insertAfter(mycard);
	l.insertAfter(mycard);
	l.insertAfter(mycard);
	l.insertAfter(mycard);
	l.insertAfter(mycard);
	
	l.gotoBeginning();
	l.gotoNext();
	l.gotoNext();
	l.gotoPrior();

	l.remove(grab);
	cout << "grabbed.... " << grab << endl << endl;
	cout << l;
	cout << endl << endl;
	
	l.gotoEnd();
	l.replace(newcard);
	cout << l;
	cout << endl << endl;

	l.clear();
	cout << l;
	cout << "SHOULD BE HERE";
	
	l.clear();

	return 0;
}
