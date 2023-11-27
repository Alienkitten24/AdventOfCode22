#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

int part_one () {

    std::string line;
    std::ifstream input ("day3input.txt");
    int sum = 0;

    while (getline(input, line)) {
        std::unordered_set<char> charSet;
        std::unordered_set<char> duplicates;

        for (int i = 0; i < line.size()/2; i++) {
            charSet.insert(line[i]);
        }
        
        for (int i = line.size()/2; i < line.size(); i++) {
            if (charSet.find(line[i]) != charSet.end()) {
                duplicates.insert(line[i]);
            }
        }

        for (auto & elem : duplicates) {
            if (int(elem) >= int('a')) {
                sum += int(elem) - int('a') + 1;
            }
            else {
                sum += int(elem) - int('A') + 27;
            }
        }
    }
    
    return sum;
}

int part_two () {

    std::string line1, line2, line3;
    std::ifstream input ("day3input.txt");
    int sum = 0;
    
    while ( std::getline(input, line1) &&
            std::getline(input, line2) &&
            std::getline(input, line3)) {
        
        std::unordered_set<char> set1, set2;
        std::unordered_set<char> duplicates;

        for (int i = 0; i < line1.size(); i++) {
            set1.insert(line1[i]);
        }

        for (int i = 0; i < line2.size(); i++) {
            set2.insert(line2[i]);
        }

        for (int i = 0; i < line3.size(); i++) {
            if (set1.find(line3[i]) != set1.end() &&
                set2.find(line3[i]) != set2.end()) {
                    duplicates.insert(line3[i]);
                } 
        }        

        for (auto & elem : duplicates) {
            if (int(elem) >= int('a')) {
                sum += int(elem) - int('a') + 1;
            }
            else {
                sum += int(elem) - int('A') + 27;
            }
        }
    }

    return sum;
}

int main () {
    // std::cout << part_one() << '\n';
    std::cout << part_two() << '\n';

    return 0;
}