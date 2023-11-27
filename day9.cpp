#include <iostream>
#include <fstream>
#include <string>

// if this is too small, it will throw a stoi error for whatever reason
// and i guess if its above 1400 it also doesn't work???
// it was allocating too much onto stack, changed it to heap allocation
const int GRID_SIZE = 2000;

struct position {
    int x;
    int y;

    position() {
        x = 0;
        y = 0;
    }

    position(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void operator+=(const position& p)
    {
        x += p.x;
        y += p.y;
    }
};

position find_direction (char direction) {
    position move(0, 0);

    switch (direction) {
        case 'L':
            move.x = -1;
            break;
        case 'R':
            move.x = 1;
            break;
        case 'U':
            move.y = -1;
            break;
        case 'D':
            move.y = 1;
            break;
    }

    return move;
}

position find_path (position head, position tail) {
    position next_move(0, 0);

    // tail within range of head
    if (((head.y - 1) <= tail.y) && (tail.y <= (head.y + 1)) &&
        ((head.x - 1) <= tail.x) && (tail.x <= (head.x + 1))) { 
            return next_move;
    }

    if (tail.y == head.y) // on same row
        next_move.y = 0;
    else if (tail.y < head.y) // tail above head
        next_move.y = 1;
    else // tail below head
        next_move.y = -1;

    if (tail.x == head.x) // on same col
        next_move.x = 0;
    else if (tail.x < head.x) // tail to left of head
        next_move.x = 1;
    else // tail to right of head
        next_move.x = -1;

    return next_move;    
}

int part_one () {
    auto grid = new bool[GRID_SIZE][GRID_SIZE];
    struct position head = {GRID_SIZE/2, GRID_SIZE/2};
    struct position tail = {GRID_SIZE/2, GRID_SIZE/2};

    std::string direction, movements;
    std::ifstream input ("day9input.txt");

    while ( getline(input, direction, ' ') && 
            getline(input, movements)) {
        
        position move_head = find_direction(direction[0]);

        for (int i = 0; i < std::stoi(movements); i++) {
            head += move_head;
            tail += find_path(head, tail);
            grid[tail.y][tail.x] = true;  
        }
    }

    int num_visited = 0;    
    for (int r = 0; r < GRID_SIZE; r++) {
        for (int c = 0; c < GRID_SIZE; c++) {
            // std::cout << ((grid[r][c]) ? "#" : ".");
            if (grid[r][c]) {
                num_visited += 1;
            }
        }    
        // std::cout << "\n";
    }

    delete[] grid;
    return num_visited;
}

int part_two () {
    auto grid = new bool[GRID_SIZE][GRID_SIZE];
    position rope[10];
    for (auto &knot : rope) {
        knot.x = GRID_SIZE/2;
        knot.y = GRID_SIZE/2;
    }
    
    std::string direction, movements;
    std::ifstream input ("day9input.txt");

    while ( getline(input, direction, ' ') && 
            getline(input, movements)) {

        position move_head = find_direction(direction[0]);

        for (int i = 0; i < std::stoi(movements); i++) {
            rope[0] += move_head;
            for (int i = 1; i < 10; i++) {  
                rope[i] += find_path(rope[i-1], rope[i]);;
            }
            grid[rope[9].y][rope[9].x] = true;
        }
    }

    
    int num_visited = 0;
    for (int r = 0; r < GRID_SIZE; r++) {
        for (int c = 0; c < GRID_SIZE; c++) {
            // std::cout << ((grid[r][c]) ? "#" : ".");
            if (grid[r][c]) {
                num_visited += 1;
            }
        }    
        // std::cout << "\n";
    }

    delete[] grid;
    return num_visited;
}

int main () {
    std::cout << "Part One: " << part_one() << "\n";
    std::cout << "Part Two: " << part_two() << "\n";
}
