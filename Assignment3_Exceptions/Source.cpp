#include "readint.h"
#include <iostream>

int main() {

	int low, high;
	std::cout << "Enter the range of values to be read.\n";
	std::cout << "Low: ";
	std::cin >> low;
	std::cout << "High: ";
	std::cin >> high;
	
	try {
		int number = read_int("Please enter a number within the range: ", low, high);
		std::cout << "You entered " << number << std::endl;
	}
	catch (std::invalid_argument &ex) {
		std::cerr << ex.what();
	}
	
	system("PAUSE");
}