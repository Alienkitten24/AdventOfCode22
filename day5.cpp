#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void print_vec_of_vecs (std::vector<std::vector<char>> stacks_list) {

    for (auto &vecs : stacks_list) {
        for (auto &elems : vecs) {
            std::cout << elems << ' ';
        }
        std::cout << '\n';
    }
}

std::string part_one () {

    std::string line;
    std::ifstream input ("day5input.txt");
    std::vector<std::vector<char>> stacks_list;
    int num_of_stacks = 9;
    int max_stack_height = 8;
    
    for (int i = 0; i < num_of_stacks; i++) {
        std::vector<char> s; 
        stacks_list.push_back(s);
    }

    int line_number = 1;
    while (getline(input, line)) {
        if (line_number <= max_stack_height) { 
            int start_offset = 1;
            int format_padding = 4;

            for (int i = start_offset; i < line.size(); i += format_padding) {
                if (line[i] != ' ') {
                    stacks_list[i/format_padding].push_back(line[i]);
                }   
            }
        }

        else if (line_number == 9) {
            // pass
        }
        
        else if (line_number == 10) {
            for (int i = 0; i < stacks_list.size(); i++) {
                std::reverse(stacks_list[i].begin(), stacks_list[i].end());
            }
        }
        
        else {
            int source, dest, rearrangements = 0;
            int format_padding = 5;

            std::sscanf(line.c_str(), "move %d from %d to %d", &rearrangements, &source, &dest);

            //change to zero based index
            source--;
            dest--;

            for (int i = 0; i < rearrangements; i++) {
                stacks_list[dest].push_back(stacks_list[source].back());
                stacks_list[source].pop_back();
            }

        }
    
        line_number++;
    }


    std::string output;
    for (int i = 0; i < stacks_list.size(); i++) {
       output.push_back(stacks_list[i].back());
    }

    return output;
}

std::string part_two () {

    std::string line;
    std::ifstream input ("day5input.txt");
    std::vector<std::vector<char>> stacks_list;
    int num_of_stacks = 9;
    int max_stack_height = 8;
    
    for (int i = 0; i < num_of_stacks; i++) {
        std::vector<char> s; 
        stacks_list.push_back(s);
    }

    int line_number = 1;
    while (getline(input, line)) {
        
        if (line_number <= max_stack_height) { 
            int start_offset = 1;
            int format_padding = 4;

            for (int i = start_offset; i < line.size(); i += format_padding) {
                if (line[i] != ' ') {
                    stacks_list[i/format_padding].push_back(line[i]);
                }   
            }
        }

         else if (line_number == 9) {
            // pass
        }

        else if (line_number == 10) {
            for (int i = 0; i < stacks_list.size(); i++) {
                std::reverse(stacks_list[i].begin(), stacks_list[i].end());
            }
        }
        
        else {
            int source, dest, rearrangements = 0;
            int format_padding = 5;

            std::sscanf(line.c_str(), "move %d from %d to %d", &rearrangements, &source, &dest);

            //change to zero based index
            source--;
            dest--;

            for (int i = stacks_list[source].size() - rearrangements;
                 i < stacks_list[source].size(); i++) {
                    stacks_list[dest].push_back(stacks_list[source][i]);
            }


            stacks_list[source].resize(stacks_list[source].size() - rearrangements);

        }
    
        line_number++;
    }


    std::string output;
    for (int i = 0; i < stacks_list.size(); i++) {
       output.push_back(stacks_list[i].back());
    }

    return output;
}


int main () {
    std::cout << part_one() << '\n';
    std::cout << part_two() << '\n';

    return 0;
}