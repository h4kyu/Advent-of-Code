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

std::pair<int, int> split_rule(const std::string& rule, const char delimiter) {
    size_t pos{rule.find(delimiter)};

    if (pos == std::string::npos) return {};

    int firstPage{std::stoi(rule.substr(0, pos))};
    int secondPage{std::stoi(rule.substr(pos+1))};

    return {firstPage, secondPage};
}

std::vector<int> split_update(const std::string& update, const char delimiter) {
    std::vector<int> updateParsed{};
    std::stringstream updateStream(update);
    std::string page{};

    while (std::getline(updateStream, page, delimiter)) {
        updateParsed.push_back(std::stoi(page));
    }

    return updateParsed;
}

int main() {
    // std::string input{read_file("input.txt")};
    std::string input{read_file("test.txt")};

    split_rule("47|53", '|');

    return 0;
}
