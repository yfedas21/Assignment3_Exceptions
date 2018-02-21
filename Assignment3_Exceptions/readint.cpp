#include <ios>
#include <limits>
#include <string>
#include <iostream>
#include <stdexcept>

int read_int(const std::string &prompt, int low, int high) {
	std::cin.exceptions(std::ios::failbit);
	
	int num = 0; 
	while (true) {
		try {
			std::cout << prompt;
			std::cin >> num;

			if (num <= low || num >= high) {
				throw std::range_error("range_error: the number you entered is out of range.");
			}
			else
				return num;
		}
		catch (std::ios_base::failure &ex) {
			std::cout << "ios_base::failure: Bad numeric string -- try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		catch (std::range_error &ex) {
			std::cerr << ex.what() << std::endl;
		}
	}

}