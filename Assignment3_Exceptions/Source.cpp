#include "readint.h"
#include <iostream>

int main() {

	int low, high;
	do {
		try {
			std::cin.exceptions(std::ios::failbit | std::ios::badbit);

			std::cout << "Enter the range of values to be read.\n";
			std::cout << "Low: ";
			std::cin >> low;
			std::cout << "High: ";
			std::cin >> high;

			if (low >= high) {
				throw std::invalid_argument("invalid_argument: the upper bound must be greater than the lower bound.");
			}
			
			break;  // Exit the loop if valid characters were entered
		}
		catch (std::invalid_argument &ex) {
			std::cerr << ex.what() << std::endl;
		}
		catch (std::ios_base::failure &ex) {
			std::cout << "ios_base::failure: Bad numeric string -- try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	} while (true);
	

	try {
		int number = read_int("Please enter a number within the range: ", low, high);
		std::cout << "You entered " << number << std::endl;
	}
	catch (std::invalid_argument &ex) {
		std::cerr << ex.what();
	}


	system("PAUSE");
}