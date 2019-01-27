#include"rectangle.h"
#include<iostream>
using namespace std;
void showCoordinate(double coor[][2]);
void sortCoordinate(double coor[][2]);
void swap(double coor[][2], int, int);
bool isRectangle(double coor[][2]);
Rectangle::Rectangle()//constructor
{
	setCorners();
}
void Rectangle::setCorners()//set the coordinates and repeat itself until the coordinates forms a rectangle 
{
	do{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << "Enter the value of ";
				if (j == 0)
					cout << "X";
				else
					cout << "Y";
				cout << " coordinate for point " << i + 1 << endl;
				cin >> coordinate[i][j];
				while (coordinate[i][j] < 0 || coordinate[i][j]>20)
				{
					cout << "wrong input, try again" << endl;
					cin >> coordinate[i][j];
				}
			}
		}
		cout << "This is the coordinate you've entered" << endl;
		showCoordinate(coordinate);
		sortCoordinate(coordinate);

		if (!isRectangle(coordinate))
			cout << "This is not a rectangle. You will not have access to other function until the coordinates specify a rectangle, please try again" << endl;
		else
			cout << "This is, indeed, a rectangle" << endl;
	} while (!isRectangle(coordinate));
}
double Rectangle::getWidth()//return the width of the rectangle 
{
	if ((coordinate[0][1] - coordinate[1][1]) < (coordinate[0][0] - coordinate[2][0]))
		return (coordinate[0][1] - coordinate[1][1]);
	else
		return (coordinate[0][0] - coordinate[2][0]);
}
double Rectangle::getLength()//return the length of the rectangle
{
	if ((coordinate[0][1] - coordinate[1][1]) > (coordinate[0][0] - coordinate[2][0]))
		return (coordinate[0][1] - coordinate[1][1]);
	else
		return (coordinate[0][0] - coordinate[2][0]);
}
double Rectangle::getPerimeter()//return the perimater of the rectangle 
{
	return ((coordinate[0][1] - coordinate[1][1]) + (coordinate[0][0] - coordinate[2][0])) * 2;
}
double Rectangle::getArea()//return the area of the rectangle 
{
	return (coordinate[0][1] - coordinate[1][1]) * (coordinate[0][0] - coordinate[2][0]);
}

void showCoordinate(double coor[][2])//shows the coordinates 
{
	for (int i = 0; i < 4; i++)
	{
		cout << "(";
		for (int j = 0; j < 2; j++)
		{
			cout << coor[i][j];
			if (j == 0)
				cout << ",";
		}
		cout << ")";
		if (i < 3)
			cout << ",";
	}
	cout << endl;
}
void swap(double coor[][2], int a, int b)//swap coordinate a and b
{
	double x, y;
	x = coor[a][0];
	y = coor[a][1];
	coor[a][0] = coor[b][0];
	coor[a][1] = coor[b][1];
	coor[b][0] = x;
	coor[b][1] = y;
}
void sortCoordinate(double coor[][2])//sort the coordinate in a particular order
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3 - i; j++)
		{
		if (coor[j][0] < coor[j + 1][0])
			swap(coor, j, j + 1);
		else if ((coor[j][0] == coor[j + 1][0]) && (coor[j][1] < coor[j + 1][1]))
			swap(coor, j, j + 1);
		}
}
bool isRectangle(double coor[][2])//return true if the coordinate is a rectangle and false other wise
{
	if ((coor[0][0] == coor[1][0]) && (coor[2][0] == coor[3][0]) && (coor[0][1] == coor[2][1]) && (coor[1][1] == coor[3][1]) && (coor[0][1] - coor[1][1] != 0) && (coor[0][0] - coor[2][0] != 0))
		return true;
	else
		return false;
}
