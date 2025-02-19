#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


bool is_safe(std::vector<int>& levels) {
    int prevLevel{levels[0]};
    int currLevel{levels[1]};

    if (prevLevel == currLevel || abs(currLevel - prevLevel) > 3) return false;

    bool isIncreasing{currLevel - prevLevel > 0};

    if (isIncreasing) {
        for (int i{2}; i < levels.size(); ++i) {
            prevLevel = currLevel;
            currLevel = levels[i];
            if (abs(currLevel - prevLevel) > 3 || currLevel <= prevLevel) return false;
        }
    } else {
        for (int i{2}; i < levels.size(); ++i) {
            prevLevel = currLevel;
            currLevel = levels[i];
            if (abs(prevLevel - currLevel) > 3 || currLevel >= prevLevel) return false;
        }
    }

    return true;
}


int part_1(std::string input) {
    std::istringstream inputStream(input);
    int safeCount{0};
    std::string line;

    while (std::getline(inputStream, line)) {
        std::istringstream stream(line);
        int level{};
        std::vector<int> levels{};

        while (stream >> level) {
            levels.push_back(level);
        }

        if (is_safe(levels)) ++safeCount;
    }
    return safeCount;
}

int main() {
    // read file line by line
    std::ifstream file("input.txt");
    // std::ifstream testFile("test.txt");
    if (!file) { // test if file is opened
        std::cout << "failed" << std::endl;
        return 1;
    }
    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    // std::string testInput((std::istreambuf_iterator<char>(testFile)), std::istreambuf_iterator<char>());
    // part 1
    std::cout << part_1(input) << std::endl;
    // std::cout << part_1(testInput) << std::endl;
}
