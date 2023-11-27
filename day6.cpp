#include <iostream>
#include <fstream>
#include <unordered_set>

int main () {

    std::ifstream input ("day6input.txt");
    std::string line;
    int marker_size = 14;

    getline(input, line);
    // std::cout << line.size() << std::endl;
     
    for (int i = 0; i < line.size(); i++) {
        
        std::unordered_set<char> hash_map;

        for (int j = i; j < i + marker_size; j++) {
            if (hash_map.find(line[j]) == hash_map.end()) {
                hash_map.insert(line[j]);
            }
            else {
                break;
            }
        }

        if (hash_map.size() == marker_size) {
            std::cout << i + marker_size;
            break;
        }
    }

    return 0;
}