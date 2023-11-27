#include <iostream>
#include <fstream>
#include <string>

int part_one () {
    std::string line;
    std::ifstream input ("day2input.txt");
    char opponent, response;
    int score = 0;

    while (getline(input, line)) {
        opponent = line[0];
        response = line[2];
        
        switch (response) {
            case 'X':
                score += 1;
                response = 'A';
                break;
            case 'Y':
                score += 2;
                response = 'B';
                break;
            case 'Z':
                score += 3;
                response = 'C';
                break;
        }

        if (opponent == response) {
            score += 3;
        }
        else {
            switch (opponent) {
                case 'A':
                    if (response == 'B') {
                        score += 6;
                    }                    
                    break;
                case 'B':
                    if (response == 'C') {
                        score += 6;
                    }
                    break;
                case 'C':
                    if (response == 'A') {
                        score += 6;
                    }
                    break;
            }
        }

    }
    
    input.close();
    return score;
}

int part_two () {
    std::string line;
    std::ifstream input ("day2input.txt");
    char opponent, outcome;
    int score = 0;

    while (getline(input, line)) {
        opponent = line[0];
        outcome = line[2];

        switch (outcome) {
            case 'X':
                switch (opponent) {
                    case 'A':
                        score += 3;
                        break;
                    case 'B':
                        score += 1;
                        break;
                    case 'C':
                        score += 2;
                        break;
                }
                break;
            case 'Y':
                score += 3;
                switch (opponent) {
                    case 'A':
                        score += 1;
                        break;
                    case 'B':
                        score += 2;
                        break;
                    case 'C':
                        score += 3;
                        break;
                }
                break;
            case 'Z':
                score += 6;
                switch (opponent) {
                    case 'A':
                        score += 2;
                        break;
                    case 'B':
                        score += 3;
                        break;
                    case 'C':
                        score += 1;
                        break;
                }
                break;
        }      
    }

    input.close();
    return score;
}

int main () {
    std::cout << part_one() << '\n';
    std::cout << part_two() << '\n';
    return 0;
}