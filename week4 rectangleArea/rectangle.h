#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

class Rectangle
{
private:
	double coordinate[4][2];//array represent the four sets of coordinates
public:
	double getWidth();
	double getLength();
	double getPerimeter();
	double getArea();
	void setCorners();
	Rectangle();


};
#endif 
