/*
Austin Kao
1/29/2018
class integer
this program allows user to set, get, increment and decrement intergers using classes.
*/
#include <iostream>
#include "rectangle.h"
using namespace std;

int main()
{
	Rectangle n1;
	int n;
	bool repeat = true;
	cout << "Please choose one of the following options by entering the corresponding number" << endl;
	do//show menu 
	{
		cout << "1) show width " << endl;
		cout << "2) show length " << endl;
		cout << "3) show perimeter " << endl;
		cout << "4) show area " << endl;
		cout << "5) reset coordinates " << endl;
		cout << "6) quit " << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "the width of the rectangle is " << n1.getWidth() << endl;
			break;
		case 2:
			cout << "the length of the rectangle is " << n1.getLength() << endl;
			break;
		case 3:
			cout << "the perimeter of the rectangle is " << n1.getPerimeter() << endl;
			break;
		case 4:
			cout << "the area of the rectangle is " << n1.getArea() << endl;
			break;
		case 5:
			n1.setCorners();
			break;
		case 6:
			repeat = false;
			break;
		default:
			cout << "Invalid Entry." << endl;
			break;
		}
	} while (repeat == true);//repeat until user exit the program

	cin.ignore();
	cin.get();
	return 0;
}

