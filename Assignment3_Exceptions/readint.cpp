#include <ios>
#include <limits>
#include <string>
#include <iostream>
#include <stdexcept>

int read_int(const std::string &prompt, int low, int high) {
	std::cin.exceptions(std::ios_base::failbit);
	int num = 0; 

	while (true) {
		try {
			std::cout << prompt;
			std::cin >> num;
			if (low >= high || high <= low) {
				throw std::invalid_argument("invalid_exception: The upper bound must be greater than the lower bound.");
			}
			else if (num <= low || num >= high) {
				throw std::range_error("range_error: Enter a valid number.\n");
			}

			else {
				return num;
				break;
			}
		}
		catch (std::range_error &ex) {
			std::cerr << ex.what() << std::endl;
		}
		catch (std::invalid_argument &ex) {
			std::cerr << ex.what() << std::endl;
		}
		catch (std::ios_base::failure &ex) {
			std::cout << "Bad numeric string -- try again.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	}
}