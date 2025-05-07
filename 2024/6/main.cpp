#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>

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
 *    TODO keep above looping logic for part 2, but part 1 assumes guard steps out of bounds
 *
 */

class Map {
private:
    std::vector<std::vector<char>> currMap;
    std::unordered_set<char> directions = {'^', '>', 'v', '<'};

    // get guard location
    std::pair<int, int> get_guard_location(std::vector<std::vector<char>> map) {
        // iterate over chars in map
        for (int row{0}; row < map.size(); ++row) {
            for (int col{0}; col < map[0].size(); ++col) {
                char currSpace{map[row][col]};
                // TODO consider storing position of obstacles in first pass
                if (directions.count(currSpace)) {
                    return {row, col};
                }
            }
        }
        return {0, 0};
    }

    // get guard direction

    // move guard
public:
    // constructor, parse input as a 2D array
    explicit Map(const std::string& input) {
        std::stringstream ss(input);
        std::string line{};

        while (std::getline(ss, line)) {
            currMap.push_back(std::vector<char>(line.begin(), line.end()));
        }


    }

    // get number of tiles traversed

};


int main() {
    // std::string input{read_file("input.txt")};
    std::string input{read_file("test.txt")};


    return 0;
}
