#include <iostream>
using namespace std;
class Length
{
private:
	int feet;
	int inches;
public:
	Length(int, int);
	Length();
	void setData();
	void setFeet(int);
	void setInches(int);
	int getFeet();
	int getInches();
	void operator ++();
	Length operator+(const Length&);

};
Length::Length()
{
	setData();
}
Length::Length(int f, int i)
{
	feet = f;
	inches = i;
}
void Length::setFeet(int f)//set the feet
{
	feet = f;
}
void Length::setInches(int i)//set inches and check the value
{
	inches = i;
	if (inches<0)
	{
		cout << "inches are outside the allowed range, setting inches to 0" << endl;
		inches = 0;
	}
	if (inches>11)
	{
		feet++;
		cout << "inches are outside the allowed range, setting feet to " << feet << " and inches to 0" << endl;
		inches = 0;
	}
}
int Length::getFeet()//return feet
{
	return feet;
}
int Length::getInches()//return inches
{
	return inches;
}
void Length::operator ++()//+= operator
{
	inches += 1;
	if (inches >= 12)
	{
		inches -= 12;
		feet += 1;
	}
}
Length Length::operator+(const Length& a)//add operator
{
	Length length(0, 0);
	length.feet = this->feet + a.feet;
	length.inches = this->inches + a.inches;
	if (length.inches >= 12)
	{
		length.inches -= 12;
		length.feet += 1;
	}
	return length;
}
void Length::setData()//set value of length and inches
{
	int t;
	cout << "Please enter the value of feet" << endl;
	cin >> t;
	setFeet(t);
	cout << "Please enter the value of inches" << endl;
	cin >> t;
	setInches(t);
}
int main()
{
	cout << "Length n1 has been declared" << endl;
	Length n1, n2(0, 0);
	int n;
	int t;
	bool repeat = true;
	cout << "Please choose one of the following options by entering the corresponding number" << endl;
	do//show menu 
	{
		cout << "1) show feet" << endl;
		cout << "2) show inches" << endl;
		cout << "3) change feet" << endl;
		cout << "4) change inches" << endl;
		cout << "5) Incerment the value of inches" << endl;
		cout << "6) define a new length n2 and adds the new length to current length" << endl;
		cout << "7) quit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "the value of feet in this length is " << n1.getFeet() << endl;
			break;
		case 2:
			cout << "the vaule of inches in this length is " << n1.getInches() << endl;
			break;
		case 3:
			cout << "enter the new value of feet" << endl;
			cin >> t;
			n1.setFeet(t);
			break;
		case 4:
			cout << "enter the new value of inches" << endl;
			cin >> t;
			n1.setInches(t);
			break;
		case 5:
			cout << "Incrementing the value of inches" << endl;
			++n1;
			break;
		case 6:
			cout << "Length n2 have been declared" << endl;
			n2.setData();
			n1 = n1 + n2;
			cout << "the value of length n2 have being added to current length" << endl;
			break;
		case 7:
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