#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	std::ifstream istream("input");

	(istream.is_open()) ? 0 : (std::cout << "Failed to open file!" << std::endl, exit(1), 1);

	std::string line;
	int cal[2] = {0, 0}; //0 = cur, 1 = max

	while (std::getline(istream, line)) {
		if (line == "") {
			if (cal[0] > cal[1]) cal[1] = cal[0];
			cal[0] = 0;
			continue;
		}

		cal[0] += std::stoi(line);
	}

	std::cout << cal[1] << std::endl;
}