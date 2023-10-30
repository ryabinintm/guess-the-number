#include "high_scores.h"

#include <fstream>
#include <iostream>
#include <string>

void read_high_scores(std::string file) {
	std::ifstream in_file(file);
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: "
				<< file << '!' << std::endl;
		return;
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


void write_high_scores(std::string file, std::string username, int attempts) {
	std::ofstream out_file(file, std::ios_base::app);
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: "
				<< file << '!' << std::endl;
		return;
	}
	out_file << username << ' ';
	out_file << attempts;
	out_file << std::endl;
	out_file.close();
}
