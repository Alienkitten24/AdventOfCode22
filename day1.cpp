#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    
    std::string line;
    std::ifstream input ("day1input.txt");
    std::vector<int> calories;
    int sum = 0;

    while (getline(input, line)) {
        if (line.empty()) {
            calories.push_back(sum);
            sum = 0;
        }
        else {
            sum += std::stoi(line);
        }
    }
    
    input.close();

    int max = calories[0];
    for (int i = 0; i < calories.size(); i++) {  
        for (int j = 0; j < calories.size() - i; j++) {
            if (calories[j] < calories[j + 1]) {
                int temp = calories[j];
                calories[j] = calories[j + 1];
                calories[j + 1] = temp;
            }
        }
    }
    

    int second_sum = 0;
    for (int i = 0; i < 3; i++) { 
        second_sum += calories[i];
    }
    
    std::cout << second_sum << '\n';


    return 0;
}


