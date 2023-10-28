#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream istream("input");

	(istream.is_open()) ? 0 : (std::cout << "Failed to open file!" << std::endl, exit(1), 1);

    std::string rucksack;
    int sum = 0;

	while (istream >> rucksack) {
        uint8_t middle = rucksack.size()/2;

        for(uint8_t i = 0; i < middle; i++) { // Scan compartment 2 for any similar character from compartment 1
            if(rucksack.find(rucksack[i], middle) != std::string::npos) { // If we find a character from compartment 1 in compartment 2...
                char matched = rucksack[i];
                sum += (matched+((96/matched)*58))-96; // Convert a-z to 1-26 & A-Z to 27-52, then add to sum.
                break;
            }
        }
    }

    std::cout << sum << std::endl;
}