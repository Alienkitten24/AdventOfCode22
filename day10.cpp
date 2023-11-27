#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::string line;
    std::ifstream input ("day10input.txt");
    int cycle = 1;
    int x_register = 1;
    int signal_strength = 0;
    char crt[6][40] = {};
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 40; c++) {
            crt[r][c] = c + 65;
        }
    }
    int sprite_pos = 1; // represents pos of center of sprite 
    int k = 0;

    while (getline(input, line)) {
        int stall = 0;
        for (int i = 0; i <= stall; i++) {
            std::cout << "cycle " << cycle << " sprite " << sprite_pos <<"\n";
            // this if statement is wrong, we dont need to check the bounds of 
            // cycle, but we need to do the left and right of sprite_pos
            if ((sprite_pos-1) <= cycle && cycle <= (sprite_pos+2)) {
                std::cout << (cycle-1)/40 << "\t" << (cycle-1)%40 << "\n";
                crt[(cycle-1)/40][(cycle-1)%40] = '#';
            }

            if (cycle > 220) {
                break;
            }
            if (!((cycle - 20) % 40)) {
                signal_strength += (x_register * cycle);
            }
            if (line.substr(0, 4) == "addx") {
                if (stall) {
                    x_register += std::stoi(line.substr(4, line.size()-4));   
                }             
                stall = 1;
            }    
            // sprite_pos = x_register;
            if (cycle== 3) {
                sprite_pos = 15;
            }
            cycle++;
        }
    }

    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 40; c++) {
            std::cout << crt[r][c];
        }
        std::cout << "\n";
    }

    std::cout << "Part One: " << signal_strength << "\n";
    return 0;
}