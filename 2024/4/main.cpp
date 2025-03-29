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

const std::array<char, 4> XMAS = {'X', 'M', 'A', 'S'};
const std::array<char, 4> SAMX = {'S', 'A', 'M', 'X'};

bool array_has_xmas(const std::array<char, 4>& arr) {
    return arr == SAMX || arr == XMAS;
}

std::array<char, 4> get_first_column(const std::vector<std::vector<char>>& block, int col) {
    std::array<char, 4> result;
    for (int i = 0; i < 4; i++) {
        result[i] = block[i][col];
    }
    return result;
}

std::array<char, 4> get_first_row(const std::vector<std::vector<char>>& block, int row) {
    std::array<char, 4> result;
    for (int i = 0; i < 4; i++) {
        result[i] = block[row][i];
    }
    return result;
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
