#include "random_number.h"

#include <ctime>
#include <cstdlib>

int get_random_number(int max_value) {
	std::srand(std::time(nullptr));
	return std::rand() % max_value;
}
