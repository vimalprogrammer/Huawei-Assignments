/*
Copy Constructor

A copy constructor is a member function that initializes an object using another object of the same class.

*/

#include<iostream>
using namespace std;

class sum
{
private:
	int x, y;
public:
	sum(int x1, int y1) { 
	x = x1; 
	y = y1; 
	}

	// Copy constructor
	sum(const sum &s1) {
	x = s1.x;
	y = s1.y;
	}

	int getSum()		 { return x + y; }
};

int main()
{
	sum s1(10, 15); // Normal constructor
	sum s2 = s1; // Copy constructor

	cout << "p1.sum = " << s1.getSum() << endl;
	cout << "p2.sum = " << s2.getSum() << endl;

	return 0;
}