#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main() {
	const int max_value = 100;
	std::srand(std::time(nullptr));
	const int target_value = std::rand() % max_value;
	
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
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win! attempts = " << attempts << std::endl;
			not_win = false;
		}
	}
	while (not_win);

	const std::string high_scores_filename = "high_scores.txt";
	std::ofstream out_file(high_scores_filename, std::ios_base::app);
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: "
				<< high_scores_filename << '!' << std::endl;
		return -1;
	}
	out_file << username << ' ';
	out_file << attempts;
	out_file << std::endl;
	out_file.close();

	std::ifstream in_file(high_scores_filename);
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for write: "
				<< high_scores_filename << '!' << std::endl;
		return -1;
	}
	std::cout << "\nHigh scores table:" << std::endl;
	std::string user;
	int value = 0;
	while (true) {
		in_file >> user;
		in_file >> value;
		in_file.ignore();
		if (in_file.fail()) {
			break;
		}
		std::cout << user << '\t' << value << std::endl;
	}
}
