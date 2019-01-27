/*
Austin Kao
3/5/2018
project 8
*/
#include<iostream>
#include<sstream>
#include <iomanip>
#include <limits>
using namespace std;
double cinDouble();
int cinInt();
bool TF();
static int pcount = 1;
class Publication
{
private:
	string title, authorName;
	double price;
public:
	void setTitle(string);
	void setAuthorName(string);
	void setPrice(double);
	string getTitle();
	string getAuthorName();
	double getPrice();
	Publication();
	Publication(string, string, double);
};
void Publication::setTitle(string n)
{
	title = n;
}
void Publication::setAuthorName(string n)
{
	authorName = n;
}
void Publication::setPrice(double n)
{
	price = n;
}
string Publication::getTitle()
{
	return title;
}
string Publication::getAuthorName()
{
	return authorName;
}
double Publication::getPrice()
{
	return price;
}
Publication::Publication()
{
	title = "";
	authorName = "";
	price = 0.0;
}
Publication::Publication(string t, string a, double p)
{
	title = t;
	authorName = a;
	price = p;
}
class Book :public Publication
{
private:
	int pageCount;
public:
	void setPageCount(int);
	int getPageCount();
	Book();
	Book(int, string, string, double);
};
void Book::setPageCount(int n)
{
	pageCount = n;
}
int Book::getPageCount()
{
	return pageCount;
}
Book::Book()
{
	pageCount = 0;
}
Book::Book(int n, string t, string a, double p) : Publication(t, a, p)
{
	pageCount = n;
}
class AudioBook :public Publication
{
private:
	int hours, minutes;
public:
	void setHours(int);
	void setMinutes(int);
	int getHours();
	int getMinutes();
	AudioBook();
	AudioBook(int, int, string, string, double);
};
void AudioBook::setHours(int n)
{
	hours = n;
}
void AudioBook::setMinutes(int n)
{
	minutes = n;
}
int AudioBook::getHours()
{
	return hours;
}
int AudioBook::getMinutes()
{
	return minutes;
}
AudioBook::AudioBook()
{
	hours = 0;
	minutes = 0;
}
AudioBook::AudioBook(int h, int m, string t, string a, double p) : Publication(t, a, p)
{
	hours = h;
	minutes = m;
}
double cinDouble()
{
	double n;
	while (true)
	{
		cin >> n;
		if (cin)
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "invalid input, try again " << endl;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (n < 0)
	{
		cout << "input is negative, setting input to 0" << endl;
		return 0;
	}
	return n;
}
int cinInt()
{
	int n;
	while (true)
	{
		cin >> n;
		if (cin)
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "invalid input, try again " << endl;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (n < 0)
	{
		cout << "input is negative, setting input to 0" << endl;
		return 0;
	}
	return n;
}
bool TF()
{
	string input;
	char ch;
	cin >> input;
	ch = input.at(0);
	while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
	{
		cout << "Invaild input, try again" << endl;
		cin >> input;
		ch = input.at(0);
	}
	if (ch == 'n' || ch == 'N')
	{
		return false;
	}
	return true;
}
void showInfor(Book, AudioBook);
void showInfor(Book b, AudioBook a)
{
	cout << "Publication " << pcount++ << endl;
	cout << "Title:  " << a.Publication::getTitle() << endl;
	cout << "Author: " << a.Publication::getAuthorName() << endl;
	cout << "Pirce:  " << a.Publication::getPrice() << endl;
	if (b.getPageCount() > 0)
	{
		cout << "Book page number: " << b.getPageCount() << endl;
	}
	if (a.getHours() != 0 || a.getMinutes() != 0)
	{
		cout << "Audio book length : " << a.getHours() << " h " << a.getMinutes() << " m" << endl;
	}
	cout << endl;
}
int main()
{
	string title, author;
	double price;
	int hour=0, minute=0, pageNum = 0;
	bool u;
	cout << "this is publication 1" << endl;
	cout << "Please enter the title of your publication " << endl;
	cin >> title;
	cout << "Please enter the author of your publication" << endl;
	cin >> author;
	cout << "Please enter the price of your publication" << endl;
	price = cinDouble();
	cout << "do you have a book for this publication?" << endl;
	u = TF();
	if (u == true)
	{
		cout << "Please enter page number" << endl;
		pageNum = cinInt();
	}
	cout << "do you have a audio book for this publication?" << endl;
	u = TF();
	if (u == true)
	{
		cout << "Please enter number of hour" << endl;
		hour = cinInt();
		cout << "Please enter number of minutes" << endl;
		minute = cinInt();
		cout << "Number of minute bigger or equal to 60, converting minute to the correct units\n";
		while (minute >= 60)
		{
			minute -= 60;
			hour++;
		}
	}
	cout << "publication 1 completed" << endl;
	Book firstBook(pageNum, title, author, price);
	AudioBook firstAudioBook(hour, minute, title, author, price);
	hour = 0, minute = 0, pageNum = 0;
	cout << "do you want to input another publication?" << endl;
	bool anotherPublication = TF();
	if (anotherPublication)
	{
		cout << "this is publication 2" << endl;
		cout << "Please enter the title of your publication " << endl;
		cin >> title;
		cout << "Please enter the author of your publication" << endl;
		cin >> author;
		cout << "Please enter the price of your publication" << endl;
		price = cinDouble();
		cout << "do you have a book for this publication?" << endl;
		u = TF();
		if (u == true)
		{
			cout << "Please enter page number" << endl;
			pageNum = cinInt();
		}
		cout << "do you have a audio book for this publication?" << endl;
		u = TF();
		if (u == true)
		{
			cout << "Please enter number of hour" << endl;
			hour = cinInt();
			cout << "Please enter number of minutes" << endl;
			minute = cinInt();
			if (minute >= 60)
				cout << "Number of minute bigger or equal to 60, converting minute to the correct units\n";
			while (minute >= 60)
			{
				minute -= 60;
				hour++;
			}

		}
		cout << "publication 2 completed\n" << endl;
	}
	Book secondBook(pageNum, title, author, price);
	AudioBook secondAudioBook(hour, minute, title, author, price);
	showInfor(firstBook, firstAudioBook);
	if (anotherPublication)
	showInfor(secondBook, secondAudioBook);
	cin.ignore();
	cin.get();
	return 0;
}

