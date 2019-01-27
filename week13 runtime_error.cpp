#include <stdexcept>
#include <iostream>
#include <limits>
#include<istream> 
#include<sstream>
#include <iomanip>
using namespace std;
class divideByZero : public runtime_error
{
public:
	divideByZero() :runtime_error{ "can't divide by zero" }{}
};
class invaildInput : public runtime_error
{
public:
	invaildInput() :runtime_error{ "input not vaild" }
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
};
int getInt()
{
	int n;
	cin >> n;
	if (cin.fail())
	{
		throw invaildInput{};
	}
	return n;
}
double divide(int n, int d)
{
	if (d == 0)
	{
		throw divideByZero{};
	}
	return static_cast<double>(n) / d;
}
int main()
{
	int n1;
	int n2;
	cout << "enter two integers and this program will print the quotient of those two numbers: \n";
	while (true)
	{
		try
		{
			n1 = getInt();
			n2 = getInt();
			double f{ divide(n1, n2) };
			cout << "the quotient is: " << f << endl;
		}
		catch (const runtime_error& error)
		{
			cout << "error : " << error.what() << endl;//the catch handler specifying the base class can catch derived-class exceptions
		}
		cout << "press q to quit(or anything else to continue)\n";
		string str = "";
		cin >> str;
		if (str == "q" || str == "Q")
			return 0;
		cout << "enter two integers: \n";
	}
	cin.ignore();
	cin.get();
	return 0;
}