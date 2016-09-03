#include <iostream>
#include <fstream>
#include "triangle.h"

using namespace std;

triangle::triangle(int b, int h)
{
	base = b;
	height = h;
	area = (b * h)/2;
}

triangle::triangle(const triangle& s)
{
	base = s.base;
	height = s.height;
	area = s.area;
}

triangle::~triangle()
{
}

triangle triangle::operator=(const triangle& s)
{
	base = s.base;
	height = s.height;
	area = s.area;
}

bool triangle::operator==(const triangle& s) const
{
	if ((base == s.base) && (height == s.height) && (area == s.area))
		{
			return true;
		}
	else
		{
			return false;
		}
}

triangle operator+(const triangle& tri1, const triangle& tri2)
{
	triangle temp;
	
	int sumb, sumh, suma;
	
	sumb = tri1.base + tri2.base;
	sumh = tri1.height + tri2.height;
	
	suma = (sumb*sumh)/2;
	
	temp.base = sumb;
	temp.height = sumh;
	temp.area = suma;
	
	return temp;
}

ostream& operator<<(ostream& cout, triangle& t)
{
	cout << "Base: " << t.base << " Height: " << t.height << " Area: " << t.area;	
}

ifstream& operator>>(ifstream& fin, triangle& t)
{
	fin >> t.base >> t.height;
	t.area = (t.base * t.height)/2;	
}


