#include <iostream>
#include <stdexcept>
#include <limits>
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
template <class T>
class Calculator
{
private:
	T number1, number2;
public:
	Calculator(T n1, T n2){ number1 = n1; number2 = n2; }
	T add(){ return number1 + number2; }
	T subtract(){ return number1 - number2; }
	T multiply(){ return number1*number2; }
	T divide()
	{
		if (number2 == 0)
		{
			throw divideByZero{};
		}
		return number1 / number2;
	}
};
template <class T>
T getResult(Calculator<T> num, char ope)
{
	switch (ope)
	{
	case '+': return num.add();
		break;
	case '-': return num.subtract();
		break;
	case '*': return num.multiply();
		break;
	case '/': return num.divide();
		break;
	}
}
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
void getInput(char type)
{
	int q, w, e, r;
	char a, s, d;
	//cout >> type >> endl;
	if (type == 'i')
	{
		try
		{
			cout << "enter a integer exception" << endl;
			q = getInt();
			cin >> a;
			w = getInt();
			Calculator<int> temp(q, w);
			cout << getResult(temp, a) << endl;
		}
		catch (const runtime_error& error)
		{
			cout << "error : " << error.what() << endl;
		}
	}
	else if (type == 'd')
	{
		try{
			cout << "enter a double exception" << endl;
			cin >> q >> a >> w >> s >> e >> d >> r;
			Calculator<double> temp(static_cast<double>(w)*0.1 + q, static_cast<double>(r)*0.1 + e);
			cout << getResult(temp, s) << endl;
		}
		catch (const runtime_error& error)
		{
			cout << "error : " << error.what() << endl;
		}
	}
}
int main()
{
	getInput('i');
	getInput('i');
	getInput('d');
	getInput('d');
	cin.ignore();
	cin.get();
	return 0;
}