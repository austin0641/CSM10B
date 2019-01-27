/*
Austin Kao 
1/29/2018
class integer 
this program allows user to set, get, increment and decrement intergers using classes. 
*/ 
#include <iostream>
#include <string>
using namespace std;

class integer//a class called integer 
{
private:
int number;// Private data member of type int
public:
void setInt (int); //allows user to set the value of int data member 
int getInt ();// allows user to get the value of int data member 
void changeInt (string);//allows user to increment or decrement the value of int data member depends on the argument  
};

void integer::setInt(int n)
{
    number = n;//set the value to it's data member 
}
int integer::getInt()
{
    return number;//return the value of it's data member
}
void integer::changeInt (string s)
{
    if (s=="increment")//increase the value of data member by one if argument == "increment"
    number++;
    else if (s=="decrement")//decrease the value of data member by one if argument == "decrement"
    number--;
    else
    cout << "invalid input"<< endl;//show "invalid input" and do nothing for all other argument 
}

int main()
{
    integer n1,n2;//instantiation of object n1 and n2
    n1.setInt(5);//set n1 to 5
    n1.changeInt("increment");//increase n1 by 1 
    n2.setInt(33);//set n2 to 33
    n2.changeInt("dfsiwf");//does nothing 
    n2.changeInt("decrement");//decrease n2 by 1 
    cout << n2.getInt() << endl;// print the value of n2
    cout << n1.getInt() << endl;// print the value of n1
    cin.ignore();
    cin.get();
    return 0;
}


