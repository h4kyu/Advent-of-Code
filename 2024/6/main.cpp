#include <iostream>
#include <fstream>

std::string read_file(const char* filename) {
    std::ifstream file(filename);
    std::string input{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    return input;
}

int main() {
    // std::string input{read_file("input.txt")};
    std::string input{read_file("test.txt")};


    return 0;
}
