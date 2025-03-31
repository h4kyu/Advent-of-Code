#include <fstream>
#include <iostream>
#include <sstream>

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

int is_xmas(const char* arr) { // assume arr is 4 characters
    if (arr[0] == 'X' && arr[1] == 'M' && arr[2] == 'A' && arr[3] == 'S') {
        return 1;
    }
    return 0;
}

int countXMAS(Grid& grid, const size_t row, const size_t col) {
    int count{0};

    char topLeftArr[4] = {grid[row][col], grid[row-1][col-1], grid[row-2][col-2], grid[row-3][col-3]};
    char topArr[4] = {grid[row][col], grid[row-1][col], grid[row-2][col], grid[row-3][col]};
    char topRightArr[4] = {grid[row][col], grid[row-1][col+1], grid[row-2][col+2], grid[row-3][col+3]};
    char rightArr[4] = {grid[row][col], grid[row][col+1], grid[row][col+2], grid[row][col+3]};
    char bottomRightArr[4] = {grid[row][col], grid[row+1][col+1], grid[row+2][col+2], grid[row+3][col+3]};
    char bottomArr[4] = {grid[row][col], grid[row+1][col], grid[row+2][col], grid[row+3][col]};
    char bottomLeftArr[4] = {grid[row][col], grid[row+1][col-1], grid[row+2][col-2], grid[row+3][col-3]};
    char leftArr[4] = {grid[row][col], grid[row][col-1], grid[row][col-2], grid[row][col-3]};

    count += is_xmas(topLeftArr) + is_xmas(topArr) + is_xmas(topRightArr) + is_xmas(rightArr) + is_xmas(bottomRightArr)
    + is_xmas(bottomArr) + is_xmas(bottomLeftArr) + is_xmas(leftArr);

    return count;
}

int part_1(std::string& input) {
    int count{0};
    std::stringstream inputStream(input);
    std::string line{};
    Grid unpaddedGrid;

    while (std::getline(inputStream, line)) {
        std::vector<char> row(line.begin(), line.end());
        unpaddedGrid.push_back(row);
    }

    size_t numRows{unpaddedGrid.size()};
    size_t numCols{unpaddedGrid[0].size()};

    Grid paddedGrid(numRows + 6, std::vector<char>(numCols + 6, '.'));

    // fill paddedGrid with chars from unpaddedGrid
    for (size_t i{0}; i < numRows; ++i) {
        for (size_t j{0}; j < numCols; ++j) {
            paddedGrid[i+3][j+3] = unpaddedGrid[i][j];
        }
    }

    // iterate over chars in paddedGrid
    for (size_t i{3}; i < numRows+3; ++i) {
        for (size_t j{3}; j < numCols+3; ++j) {
            char cell{paddedGrid[i][j]};
            size_t row{i};
            size_t col{j};
            if (cell == 'X') {
                count += countXMAS(paddedGrid, row, col);
            }
        }
    }


    return count;
}

int main() {
    std::string input{read_file("input.txt")};
    // std::string input{read_file("test.txt")};

    std::cout << part_1(input) << std::endl;

    return 0;
}
