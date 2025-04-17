#include <iostream>
#include <fstream>

std::string read_file(const char* filename) {
    std::ifstream file(filename);
    std::string input{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    return input;
}

/*
 * part 1
 * parse the input as a map, 2D vectors of chars
 * traverse map to find location and direction of guard
 * move the guard incrementally, changing the map behind it accordingly
 * do so until either 1. the whole map is traversed, 2. the guard is out of bounds, 3. the guard is in a loop
 *    for loop detection, check if guard has previously been in the same position with same direction
 * 
 */

int main() {
    // std::string input{read_file("input.txt")};
    std::string input{read_file("test.txt")};


    return 0;
}
