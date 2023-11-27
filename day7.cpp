#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Node {
    public: 
        std::string name;
        int file_size; 
        std::vector<Node*> children;
        bool is_directory;

        Node(std::string s, int i, bool b) {
                name = s;
                file_size = i;
                is_directory = b;

        }        

    public: 
        void print_node() {
            std::cout << "Name: " << name << '\t';
            std::cout << "Size: " << file_size << '\t';
            std::cout << "Type: " << ((is_directory) ? "dir" : "file") << '\t';
            std::cout << "Children: ";
            for (Node* child : children) {
                std::cout << child->name << ", ";
            }
            std::cout << '\n';
        }

        void print_tree(int rec_level = 1) {
            std::cout << "- " << name << "  " 
            << ((is_directory) ? "dir" : "file") << " " << file_size << "\n";
            for (Node* child : children) {
                for (int i = 0; i < rec_level; i++) {
                    std::cout << "  ";
                }
                child->print_tree(rec_level + 1);
            }
        }

};

// recursive function
int part_two(Node* node, int smallest, int space_to_delete) {
    for (Node* child : node->children) {
        smallest = part_two(child, smallest, space_to_delete);
        if (child->file_size < smallest && child->file_size > space_to_delete
            && child->is_directory) {
            smallest = child->file_size;
        }
    }
    return smallest;
}

int main () {    
    std::string line;
    std::ifstream input ("day7input.txt");

    Node home("/", 0, true);
    std::vector<Node*> dir_stack = {&home}; 
    std::vector<Node*> part_one_answer;

    while(getline(input, line)) {

        if (line.substr(0, 4) == "$ ls") { 
            continue; 
        }
        else if (line.substr(0, 4) == "$ cd") { 
            if (line.substr(4, 3) == " ..") {
                dir_stack[dir_stack.size()-2]->file_size += dir_stack.back()->file_size;
                if (dir_stack.back()->file_size <= 100000) {
                    part_one_answer.push_back(dir_stack.back());
                }
                dir_stack.pop_back();
            }
            else {
                for (Node* child : dir_stack.back()->children) {
                    if (child->name == line.substr(5, line.size())) {
                        dir_stack.push_back(child);
                    }
                }
            }
        }
        else if (line.substr(0, 3) == "dir") {
            std::string directory_name = line.substr(4, line.size()-4);
            Node* new_node = new Node(directory_name, 0, true);
            dir_stack.back()->children.push_back(new_node);
        }
        else {
            int n = line.find(" ");
            std::string file_size = line.substr(0, n);
            std::string file_name = line.substr(n + 1, line.size() - file_size.size());
            Node* new_node = new Node(file_name, std::stoi(file_size), false);
            dir_stack.back()->children.push_back(new_node);
            dir_stack.back()->file_size += new_node->file_size;
        }
    }
    
    // workaround because we never cd back to home
    for (int i = 0; i <= dir_stack.size(); i++) { 
    // this loop was an off by one error that caused me so much pain...
    // dir stack had one extra that caused home file size to be wrong
    // which meant that part two was doomed from the start
        home.file_size += dir_stack.back()->file_size;
        dir_stack.pop_back();
    }
    
    home.print_tree();


    if (home.file_size <= 100000) {
        part_one_answer.push_back(&home);
    }
    int p1_ans = 0;
    for (Node* elem : part_one_answer) {
        // elem->print_node();
        p1_ans += elem->file_size;
    }
    std::cout << "\nPart one answer: " << p1_ans << "\n";



    int total_file_space = 70000000; 
    int required_unused_space = 30000000;
    int space_to_delete = home.file_size - (total_file_space - required_unused_space);  
    
    std::cout << "Part two answer: " 
    << part_two(&home, home.file_size, space_to_delete) << "\n";


    return 0;
}