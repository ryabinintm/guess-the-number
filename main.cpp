#include "random_number.h"
#include "high_scores.h"

#include <iostream>

int main() {
	const int max_random_value = 100;
	const int target_value = get_random_number(max_random_value); 
	
	int current_value = 0;
	bool not_win = true;

	std::string username;
	int attempts= 0;

	std::cout << "Hi! Enter your name:" << std::endl;
	std::cin >> username;
	std::cout << "Enter your guess:" << std::endl;

	do {
		attempts++;
		std::cin >> current_value;
		if (current_value < target_value) {
			std::cout << "your number " << current_value << " is less" << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "your number " << current_value << " is bigger" << std::endl;
		}
		else {
			std::cout << "you win! attempts = " << attempts << std::endl;
			not_win = false;
		}
	}
	while (not_win);

	const std::string hs_file = "high_scores.txt";
	write_high_scores(hs_file, username, attempts);
	read_high_scores(hs_file);
}
