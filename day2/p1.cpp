#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <array>

int main() {
	std::ifstream istream("input");

	(istream.is_open()) ? 0 : (std::cout << "Failed to open file!" << std::endl, exit(1), 1);

    std::map<std::array<char, 2>, uint8_t> results = {
        {{'A','Y'}, 8}, {{'A','Z'}, 3}, {{'A','X'}, 3},
        {{'B','X'}, 1}, {{'B','Z'}, 9}, {{'B','Y'}, 3},
        {{'C','X'}, 7}, {{'C','Y'}, 2}, {{'C','Z'}, 3}
    };

	std::array<char, 2> search;
    int score = 0;

	while (istream.peek() != EOF) {
        istream >> search[0]; istream >> search[1];
        score += (int)results.find(search)->second;
	}

    std::cout << score << std::endl;
}