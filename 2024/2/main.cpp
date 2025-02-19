#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// read line by line with getLine

    // if diff == 0, unsafe
    // isIncreasing = diff > 0

    // if isIncreasing,

bool is_safe(std::istringstream stream) {
    int prevLevel, currLevel;
    stream >> prevLevel >> currLevel;
    if (prevLevel == currLevel) return false;

    bool isIncreasing{prevLevel - currLevel > 0};

    while () { // walk through stream

    }
}

int main() {
    // read file line by line
    std::ifstream file("input.txt");
    if (!file) { // test if file is opened
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);

        while ()
    }

}