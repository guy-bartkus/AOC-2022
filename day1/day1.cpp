#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	std::ifstream istream("input");

	(istream.is_open()) ? 0 : (std::cout << "Failed to open file!" << std::endl, exit(1), 1);

	std::string line;
	int cur = 0;
	int max[3] = { 0, 0, 0 };

	while (std::getline(istream, line)) {
		if (line == "") {
			uint8_t smallest = 0;
			for (uint8_t i = 0; i < 3; i++) (max[i] < max[smallest]) ? smallest = i : 0;
			if (cur > max[smallest]) max[smallest] = cur;
			cur = 0;
			continue;
		}

		cur += std::stoi(line);
	}

	std::cout << max[0] + max[1] + max[2] << std::endl;
}