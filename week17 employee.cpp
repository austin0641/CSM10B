#include<istream>
#include<fstream>
#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;
int main()
{
	ofstream outemp("employee.txt", ios::out);
	string firstName = "";
	string lastName = "";
	char middleInitial;
	unsigned long employeeNum;
	string re = "";
	bool repeat = true;
	if (!outemp)
	{
		cout << "fail to open file" << endl;
		exit(EXIT_FAILURE);
	}
	while (repeat)
	{
		cout << "enter first name" << endl;
		cin >> firstName;
		cout << "enter middle initial" << endl;
		cin >> middleInitial;
		cout << "enter last name" << endl;
		cin >> lastName;
		cout << "enter employee number" << endl;
		cin >> employeeNum;
		outemp << firstName << ' ' << lastName << ' ' << middleInitial << ' ' << employeeNum << endl;
		cout << "enter [End] if thats the last employee\n";
		cin >> re;
		if (re == "End" || re == "end" || re == "END")
			repeat = false;
	}
	outemp.close();
	ifstream inemp("employee.txt", ios::in);
	if (!inemp)
	{
		cout << "fail to open file" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Employee Number   Name\n";

	while (inemp >> firstName >> lastName >> middleInitial >> employeeNum)
	{
		cout << employeeNum << "        " << firstName << " " << middleInitial << " " << lastName << endl;
	}
	inemp.close();
	cin.ignore();
	cin.get();
	return 0;
}