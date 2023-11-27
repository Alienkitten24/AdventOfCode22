#include <iostream> 
#include <fstream>

int part_one () {

    std::string num1, num2, num3, num4;
    std::ifstream input ("day4input.txt");
    int sum = 0;

    while ( getline(input, num1, '-') && 
            getline(input, num2, ',') &&
            getline(input, num3, '-') &&
            getline(input, num4)) {

        if (std::stoi(num3) >= std::stoi(num1) && 
            std::stoi(num4) <= std::stoi(num2)) {
                sum++;
        }

        else if (std::stoi(num1) >= std::stoi(num3) &&
                 std::stoi(num2) <= std::stoi(num4)) {
                    sum++;
        }
    }

    return sum;
}

int part_two () {

    std::string num1, num2, num3, num4;
    std::ifstream input ("day4input.txt");
    int sum = 0;

    while ( getline(input, num1, '-') && 
            getline(input, num2, ',') &&
            getline(input, num3, '-') &&
            getline(input, num4)) {

        if (std::stoi(num3) <= std::stoi(num2) && 
            std::stoi(num4) >= std::stoi(num1)) {
                    sum++;
        }
        
    }

    return sum;
}

int main () {
    std::cout << part_one() << '\n';
    std::cout << part_two() << '\n';
    return 0;
}