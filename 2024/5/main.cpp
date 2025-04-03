#include <iostream>
#include <fstream>
#include <sstream>

/* part 1:
 * separate rules and updates
 * split rules by '|' delimiter and store as std::set
 * split updates by ',' delimiter and store as std::vector
 * duplicate update and use std::sort to apply all rules to each update, using lambda func as comparator rule for sort
 * compare newly sorted update with original
 */

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
