#include <iostream>
#include "peopleclass.cpp"

using namespace std;

int main()
{
	int age = 18;
	int* ss = new int[9];
	ss[3] = 7;
	int* emp = new int[5];
	emp[1] = 6;
	
	person first;
	
	first.print();
	
	cout << endl << endl;
	
	employee second;
	second.setFirstname("Carlan");
	second.setLastname("White");
	second.setAge(27);
	second.setSsn(ss);
	second.setEmpnum(emp);
	second.setSalary(250000);
	second.setTitle("MUTHAFUCKING BOSS");
	
	second.print();
	
return 0;
}
