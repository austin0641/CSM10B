#include <iostream>
#include <iomanip>
int main()
{
	std::cout << std::setw(6) << "dec" << std::setw(6) << "oct" << std::setw(6) << "hex" << std::setw(6) << "char" << std::endl;
	for (char a = 33; a <= 126; a++)
		std::cout << std::dec << std::setw(6) << int(a) << std::oct << std::setw(6) << int(a) << std::hex << std::setw(6) << int(a) << std::setw(6) << a << std::endl;
	std::cin.ignore();
	std::cin.get();
	return 0;
}