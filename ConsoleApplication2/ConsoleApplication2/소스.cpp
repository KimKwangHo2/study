#include<iostream>
#include "Circle.h"
using namespace std;

class Circle {
public:
	int radius;
	double getArea();
	Circle();
};

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

Circle::Circle()
{
	radius=5;
}

int main()
{
	Circle c;
	CCircle cc;

	cout<<c.radius<<endl;
	cout<<c.getArea()<<endl;
	cout << cc.radius << endl;
	cout << cc.gerArea() << endl;
}