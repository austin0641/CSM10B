/*
Austin Kao
3/19/2018
project 10
*/
#include<iostream>
#include<istream> 
#include<sstream>
#include <iomanip>
#include <limits>
using namespace std;
double cinDouble();
int cinInt();
static int pcount = 1;
class Publication
{
protected:
	string title, authorName;
	double price;
public:

	virtual void setTitle(string) = 0;
	virtual void setAuthorName(string) = 0;
	virtual void setPrice(double) = 0;
	virtual string getTitle() = 0;
	virtual string getAuthorName() = 0;
	virtual double getPrice() = 0;
	virtual void showInfo();

	Publication();
	virtual ~Publication();
};
Publication::Publication()
{
	title = "";
	authorName = "";
	price = 0;
}
Publication::~Publication()
{
}
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

void Publication::showInfo()
{

}

class Book :public Publication
{
private:
	int pageCount;
public:
	void setTitle(string);
	void setAuthorName(string);
	void setPrice(double);
	string getTitle();
	string getAuthorName();
	double getPrice();
	void setPageCount(int);
	int getPageCount();
	Book();
	Book(int, string, string, double);
	void showInfo();
};
void Book::showInfo()
{
	cout << "Publication: " << pcount++ << endl;
	cout << "Title:  " << title << endl;
	cout << "Author: " << authorName << endl;
	cout << "Price:  " << price << endl;
	cout << "number of page: " << pageCount << "\n\n";
}
void Book::setTitle(string n)
{
	title = n;
}
void Book::setAuthorName(string n)
{
	authorName = n;
}
void Book::setPrice(double n)
{
	price = n;
}
string Book::getTitle()
{
	return title;
}
string Book::getAuthorName()
{
	return authorName;
}
double Book::getPrice()
{
	return price;
}
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
	title = "";
	authorName = "";
	price = 0.0;
}
Book::Book(int n, string t, string a, double p)
{
	title = t;
	authorName = a;
	price = p;
	pageCount = n;
}
class AudioBook :public Publication
{
private:
	int hours, minutes;
public:
	void setTitle(string);
	void setAuthorName(string);
	void setPrice(double);
	string getTitle();
	string getAuthorName();
	double getPrice();
	void setHours(int);
	void setMinutes(int);
	int getHours();
	int getMinutes();
	AudioBook();
	AudioBook(int, int, string, string, double);
	void showInfo();
	~AudioBook(){}
};
void AudioBook::showInfo()
{
	cout << "Publication " << pcount++ << endl;
	cout << "Title:  " << title << endl;
	cout << "Author: " << authorName << endl;
	cout << "Pirce:  " << price << endl;
	cout << "Audio book length : " << hours << " h " << minutes << " m\n\n";
}
void AudioBook::setTitle(string n)
{
	title = n;
}
void AudioBook::setAuthorName(string n)
{
	authorName = n;
}
void AudioBook::setPrice(double n)
{
	price = n;
}
string AudioBook::getTitle()
{
	return title;
}
string AudioBook::getAuthorName()
{
	return authorName;
}
double AudioBook::getPrice()
{
	return price;
}
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
	title = "";
	authorName = "";
	price = 0.0;
}
AudioBook::AudioBook(int h, int m, string t, string a, double p)
{
	authorName = a;
	price = p;
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
int main()
{
	string title, author;
	double price;
	int hour = 0, minute = 0, pageNum = 0;
	bool u;
	string AorB;
	Publication *ptr[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "This is publication " << i + 1 << endl;
		cout << "Do you wnat to create a book or a audio book?\n[b]ook\n[a]udio book\n";
		getline(cin, AorB);
		char t;
		AorB = AorB + " ";
		t = AorB.at(0);
		while (t != 'b' && t != 'B' && t != 'A' && t != 'a')
		{
			cout << "Invaild input, try again" << endl;
			getline(cin, AorB);
			AorB = AorB + " ";
			t = AorB.at(0);
		}
		if (t == 'b' || t == 'B')
		{
			cout << "Please enter the title of your publication " << endl;
			getline(cin, title);
			cout << "Please enter the author of your publication" << endl;
			getline(cin, author);
			cout << "Please enter the price of your publication" << endl;
			price = cinDouble();
			cout << "Please enter page number" << endl;
			pageNum = cinInt();
			ptr[i] = new Book(pageNum, title, author, price);
		}
		else
		{
			cout << "Please enter the title of your publication " << endl;
			getline(cin, title);
			cout << "Please enter the author of your publication" << endl;
			getline(cin, author);
			cout << "Please enter the price of your publication" << endl;
			price = cinDouble();
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
			ptr[i] = new AudioBook(hour, minute, title, author, price);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		ptr[i]->showInfo();
		delete ptr[i];
	}
	cin.ignore();
	cin.get();
	return 0;
}