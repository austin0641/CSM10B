#include <iostream>
#include <vector>
using namespace std;
template <typename T>
bool palindrome(vector <T> vec)
{
	for (int i = 0; i < vec.size() / 2; i++)
	{
		if (vec[i] != vec[vec.size() - 1 - i])
			return false;
	}
	return true;
}
template <typename T>
void showResult(bool b, vector <T> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	if (b)
		cout << "This array does contains a palindrome\n";
	else
		cout << "This array does not contains a palindrome\n";
}
int main()
{
	vector <int> v1 = { 1, 2, 3, 2, 1 };
	showResult(palindrome(v1), v1);
	vector <int> v2 = { 1, 2, 3, 2, 2 };
	showResult(palindrome(v2), v2);
	vector <char> v3 = {'q','w','e','r','t','y' };
	showResult(palindrome(v3), v3);
	vector <char> v4 = { 'q','a','z','a','q' };
	showResult(palindrome(v4), v4);
	cin.ignore();
	cin.get();
	return 0;
}