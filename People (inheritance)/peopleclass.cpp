#include <iostream>
#include <cstdlib>
#include <fstream>
#include "stringfunc.cpp"

using namespace std;

class person
{
	public:
	person(char* = NULL, char* = NULL, int = 0, int* = NULL);
	~person();
	
	const char* getFirstname() const;
	bool setFirstname(const char*);
	const char* getLastname() const;
	bool setLastname(const char*);
	int getAge() const;
	bool setAge(int);
	const int* getSsn() const;
	bool setSsn(int*);
	void print() const;
	
	protected:
	char* firstname;
	char* lastname;
	int age;
	
	private:
	int* ssn;
};

person::person(char* first, char* last, int a, int* s)
{
	if (first == NULL)
		{
			firstname = new char[20];
		}
	else
		{
			firstname = first;
		}
		
	if (last == NULL)
		{
			lastname = new char[20];
		}
	else
		{
			lastname = last;
		}	
		
	age = a;
	
	if (s==NULL)
		{
			ssn = new int[9];
		}
	else
		{
			ssn = s;
		}
}

person::~person()
{
	delete[] firstname;
	delete[] lastname;
	delete[] ssn;
}

const char* person::getFirstname() const
{
	return firstname;
}

bool person::setFirstname(const char* input)
{
	strcpy(firstname, input);
	return true;
}

const char* person::getLastname() const
{
	return lastname;
}

bool person::setLastname(const char* input)
{
	strcpy(lastname, input);
	return true;
}
	
int person::getAge() const
{
	return age;
}

bool person::setAge(int input)
{
	age = input;
	return true;
}

const int* person::getSsn() const
{
	return ssn;
}

bool person::setSsn(int* input)
{
	for (int ndx = 0; ndx < 9; ndx++)	
		{
			ssn[ndx] = input[ndx];
		}
	return true;
}

void person::print() const
{
	cout << firstname << " " << lastname << " ";
	cout << "Age: " << age << " " << "Social: ";
	for (int ndx = 0; ndx < 9; ndx++)
		{
			cout << ssn[ndx];
		}
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

class employee: public person
{
	public:
	employee(int* = NULL, char* = NULL, int = 0);
	~employee();
	
	const int* getEmpnum() const;
	bool setEmpnum(int*);
	const char* getTitle() const;
	bool setTitle(const char* input);
	int getSalary() const;
	bool setSalary(int);
	void print();
	
	private:
	int* empnum;
	char* title;
	int salary;
};

employee::employee(int* number, char* t, int money)
{
	if (number==NULL)
		{
			empnum = new int [5];
		}
	else
		{
			empnum = number;
		}
		
	if (t==NULL)
		{
			title = new char[20];
		}
	else
		{
			title = t;
		}
	salary = money;
}

employee::~employee()
{
	delete[] empnum;
	delete[] title;
}

const int* employee::getEmpnum() const
{
	return empnum;
}

bool employee::setEmpnum(int* input)
{
	for (int ndx = 0; ndx < 5; ndx++)
		{
			empnum[ndx] = input[ndx];
		}
	return true;
}

const char* employee::getTitle() const
{
	return title;
}

bool employee::setTitle(const char* input)
{
	strcpy(title, input);
	return true;
}
	
int employee::getSalary() const
{
	return salary;
}

bool employee::setSalary(int input)
{
	salary = input;
	return true;
}

void employee::print()
{
	person::print();
	cout << " " << "Employee #: ";
	for (int ndx=0; ndx<5; ndx++)
		{
			cout << empnum[ndx];
		}
	cout << " " << "Title: " << title;
	cout << " " << "Salary: " << salary;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

class student:public person
{
	public:
	student();
	~student();
	
	const int* getNshe() const;
	void setNshe(int*);
	//get major
	//set major
	double getGpa() const;
	void setGpa(int);
	
	private:
	int* nshe;
	//major
	double gpa;
};

student::student()
{
}

student::~student()
{
}

const int* student::getNshe() const
{
}

void student::setNshe(int* input)
{
}

double student::getGpa() const
{
}

void student::setGpa(int input)
{
}













