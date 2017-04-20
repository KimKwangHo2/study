#include "Circle.h"



CCircle::CCircle()
{
	radius=10;
}


CCircle::~CCircle()
{
}


double CCircle::gerArea()
{
	return 3.14*radius*radius;
}