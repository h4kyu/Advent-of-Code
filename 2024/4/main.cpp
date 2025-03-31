#include <fstream>
#include <iostream>

/* pseudocode part_1
 * read and store input as 2D array (or matrix?).
 * traverse 2D array by character.
 * on X, check all 8 characters adjacent for M (if index exists)
 * if yes, do the same for A and S.
 * add to sum if XMAS is completed.
 * continue to next X.
 *
 * assume input is larger than 4x4
 *
 * create buffer of 3 on each side of 2D array
 */

std::string read_file(const char* filename) {
    std::ifstream file(filename);
    std::string input{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    return input;
}

using Grid = std::vector<std::vector<char>>;

bool is_xmas(const char* arr) { // assume arr is 4 characters
    if (arr[0] == 'X' && arr[1] == 'M' && arr[2] == 'A' && arr[3] == 'S') {
        return true;
    }
    return false;
}

int part_1(std::string input) {
    int count{0};


    return count;
}

int main() {
    std::string input{read_file("input.txt")};

    std::cout << part_1(input) << std::endl;

    return 0;
}
