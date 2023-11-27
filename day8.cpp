#include <iostream>
#include <fstream>
#include <string>

// MAKE SURE TO CHANGE THIS IN ACCORDANCE TO YOUR INPUT
const int FOREST_SIZE = 99; 

bool check_visibility (int r, int c, int grid[][FOREST_SIZE], char direction) {

    bool is_visible = true;

    for (int i = 1; i < FOREST_SIZE; i++) {
        switch (direction) {
            case 'l':
                if ((c-i) >= 0 && grid[r][c] <= grid[r][c-i]) {
                    is_visible = false;
                }
                break;
            case 'r':
                if ((c+i) < FOREST_SIZE && grid[r][c] <= grid[r][c+i]) {
                    is_visible = false;
                }
                break;
            case 'u':
                if ((r-i) >= 0 && grid[r][c] <= grid[r-i][c]) {
                    is_visible = false;
                }
                break;
            case 'd':
                if ((r+i) < FOREST_SIZE && grid[r][c] <= grid[r+i][c]) {
                    is_visible = false;
                }
                break;
        }
    }

    return is_visible;
}

int calc_scenic_score (int r, int c, int grid[][FOREST_SIZE]) {
    int l_score = 1;
    int r_score = 1;
    int u_score = 1;
    int d_score = 1;
    for (int i = 1; i < FOREST_SIZE; i++) { // l
        if ((c-i) <= 0 || grid[r][c] <= grid[r][c-i]) {
            break;
        }
        l_score += 1;
    }
    for (int i = 1; i < FOREST_SIZE; i++) { // r
        if ((c+i) >= (FOREST_SIZE-1) || grid[r][c] <= grid[r][c+i]) { 
            break;
        }
        r_score += 1;
    }
    for (int i = 1; i < FOREST_SIZE; i++) { // u
        if ((r-i) <= 0 || grid[r][c] <= grid[r-i][c]) { 
            break;
        }
        u_score += 1;
    }
    for (int i = 1; i < FOREST_SIZE; i++) { // d
        if ((r+i) >= (FOREST_SIZE-1) || grid[r][c] <= grid[r+i][c]) { 
            break;
        }
        d_score += 1;
    }
    
    return l_score * r_score * u_score * d_score;
}


int main () {
    int n = 0;
    int grid[FOREST_SIZE][FOREST_SIZE];
    std::string line;
    std::ifstream input ("day8input.txt");

    // populate grid
    while(getline(input, line)) {
        for (int i = 0; i < line.size(); i++) {
            grid[n][i] = std::stoi(line.substr(i,1)); 
        }  
        n++;
    }
    
    
    // part one
    int visible_tree_count = 0;
    visible_tree_count += (FOREST_SIZE - 1) * 4; // for every tree on the edge

    for (int r = 1; r < FOREST_SIZE - 1; r++) {
        for (int c = 1; c < FOREST_SIZE - 1; c++) {
            if (check_visibility(r, c, grid, 'l') || 
                check_visibility(r, c, grid, 'r') || 
                check_visibility(r, c, grid, 'u') || 
                check_visibility(r, c, grid, 'd')) {
                    visible_tree_count += 1;
            }
        }
    }
    std::cout << "Number of visible trees: " << visible_tree_count << "\n";


    // part two 
    int top_score = 0;
    for (int r = 1; r < FOREST_SIZE - 1; r++) {
        for (int c = 1; c < FOREST_SIZE - 1; c++) {
            int score = calc_scenic_score(r, c, grid);
            if (score > top_score) {
                top_score = score;
            }
        }
    }
    std::cout << "Top score: " << top_score;



   
    return 0;
}