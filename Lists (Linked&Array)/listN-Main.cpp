#include "listN.h"
#include <iostream>

using namespace std;

int main() {

	bool test;
	List l(10);
	char grab;
	
	test = l.insertAfter('a');
	cout << l << endl;
	test = l.insertAfter('n');
	cout << l << endl;
	test = l.insertBefore('f');
	l.remove(grab);
	cout <<grab<<endl;
	l.replace('d');
	l.getCursor(grab);
	cout << grab << endl;
	cout << l << endl;

test = l.empty();
cout << test << "SHOULD BE NO";

l.clear();

	test = l.gotoBeginning();
	test = l.gotoEnd();
	
	test = l.gotoPrior();

	cout << test;

	return 0;
}
