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

    // enum class Direction {
    //     Up,
    //     Down,
    //     Left,
    //     Right
    // };

    enum class ExitCode {
        OUT_OF_BOUNDS,
        LOOP
    };

    std::array<char, 4> directions = {'^', '>', 'v', '<'};

    // get guard location
    std::pair<int, int> get_guard_location(std::vector<std::vector<char>>& map) {
        // iterate over chars in map
        for (int row{0}; row < map.size(); ++row) {
            for (int col{0}; col < map[0].size(); ++col) {
                char currSpace{map[row][col]};
                // TODO consider storing position of obstacles in first pass
                if (std::find(directions.begin(), directions.end(), currSpace)) {
                    return {row, col};
                }
            }
        }
        return {0, 0};
    }

    // get guard direction
    int get_guard_direction(char guard) {
        if (guard == '^') return 0;
        if (guard == '>') return 1;
        if (guard == 'v') return 2;
        return 3;
    }
    // Direction get_guard_direction(char guard) {
    //     if (guard == '^') return Direction::Up;
    //     if (guard == '>') return Direction::Right;
    //     if (guard == 'v') return Direction::Down;
    //     return Direction::Left;
    // }

    // move guard
    ExitCode move_guard(std::vector<std::vector<char>>& map, std::pair<int, int> currPos, int directionIndex) {
        char spaceInFront{};
        int row{currPos.first};
        int col{currPos.second};

        if (directionIndex == 0) {
            spaceInFront = map[row-1][col];
        } else if (directionIndex == 1) {
            spaceInFront = map[row][col+1];
        } else if (directionIndex == 2) {
            spaceInFront = map[row+1][col];
        } else {
            spaceInFront = map[row][col-1];
        }

        // check for boundary
        if (spaceInFront == 'B') {
            map[row][col] = 'X';
            return ExitCode::OUT_OF_BOUNDS;
        }

        // check for obstacle
        if (spaceInFront == '#') {
            // turn guard to the right
            int nextIndex{(directionIndex + 1) % 4};
            char updatedGuard{directions[nextIndex]};
            map[row][col] = updatedGuard;
        }
    }

public:
    // constructor, parse input as a 2D array
    explicit Map(const std::string& input) {
        std::stringstream ss(input);
        std::string line{};

        // currMap.push_back(std::vector<char> boundary())

        while (std::getline(ss, line)) {
            // TODO add 'B' ring as boundary when parsing


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
