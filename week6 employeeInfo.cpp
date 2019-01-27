/*
Austin Kao 
2/15/2018
project 6 
*/
#include <iostream>
#include<string>
#include <iomanip>
using namespace std;
void showHeader();
class Employee
{
private:
	string firstName;
	string lastName;
	char gender;
	int numDependent;
	double salary;
public:
	static int numEmployee;
	Employee();
	Employee(string, string, char, int, double);
	void setFirstName(string);
	void setLastName(string);
	void setGender(char);
	void setNumDependent(int);
	void setSalary(double);
	string getFirstName();
	string getLastName();
	char getGender();
	int getNumDependent();
	double getSalary();
	static int getNumEmployee();
	double getWeeklySalary();
	void displayInformation(Employee);
};
int Employee::numEmployee = 0;
void Employee::setFirstName(string n)
{
	firstName = n;
}
void Employee::setLastName(string n)
{
	lastName = n;
}
void Employee::setGender(char n)
{
	if (n == 'F' || n == 'f')
		gender = 'F';
	else if (n == 'M' || n == 'm')
		gender = 'M';
	else
		gender = 'U';
}
void Employee::setNumDependent(int n)
{
	if (n < 0)
		numDependent = 0;
	else if (n >10)
		numDependent = 10;
	else
		numDependent = n;
}
void Employee::setSalary(double n)
{
	if (n < 50000.0)
		salary = 50000.0;
	else if (n > 250000.0)
		salary = 250000.0;
	else
		salary = n;
}
string Employee::getFirstName()
{
	return firstName;
}
string Employee::getLastName()
{
	return lastName;
}
char Employee::getGender()
{
	return gender;
}
int Employee::getNumDependent()
{
	return numDependent;
}
double Employee::getSalary()
{
	return salary;
}
int Employee::getNumEmployee()
{
	return numEmployee;
}
double Employee::getWeeklySalary()
{
	return salary / 52.0;
}
void displayInformation(Employee e)
{
	cout << "Employee information" << endl;
	for (int i = 0; i < 60; i++)
		cout << '_';
	cout << endl;
	cout << "Name:           " << e.getFirstName() <<" " << e.getLastName() << endl;
	cout << "Gender:         " << e.getGender() << endl;
	cout << "Dependents:     " << e.getNumDependent() << endl;
	cout << "Annual Salary:  "<< fixed<<setprecision(2)<< e.getSalary() << endl;
	cout << "Weekly Salary:  " << fixed << setprecision(2)<< e.getWeeklySalary() << endl;


}
Employee::Employee()
{
	firstName = "";
	lastName = "";
	gender = 'U';
	numDependent = 0;
	salary = 20000.0;
	numEmployee++;
}
Employee::Employee(string fir, string las, char gen, int numDe, double sal)
{
	setFirstName(fir);
	setLastName(las);
	setGender(gen);
	setNumDependent(numDe);
	setSalary(sal);
	numEmployee++;
}
void showHeader()
{
	cout << "\n\n********************* Employee " << Employee::getNumEmployee() + 1 << " ***************************" << endl;
}
int main()
{
	string i1, i2;
	char i3;
	int i4;
	double i5;
	cout << "CS-M10B, Week 6 exercise, Austin Kao" << endl;
	showHeader();
	cout << "Please enter your First Name ";
	cin >> i1;
	cout << "Please enter your Last Name ";
	cin >> i2;
	cout << "Please enter your Gender ";
	cin >> i3;
	cout << "Please enter your Dependents ";
	cin >> i4;
	cout << "Please enter your Annual Salary ";
	cin >> i5;
	Employee n1(i1, i2, i3, i4, i5);
	displayInformation(n1);

	showHeader();
	Employee n2;
	displayInformation(n2);

	


	cin.ignore();
	cin.get();
	return 0;
}





