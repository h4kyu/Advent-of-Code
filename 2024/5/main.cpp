#include <iostream>
#include <fstream>
#include <set>
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

bool update_is_correct(std::vector<int> update, std::set<std::pair<int, int>> rules) {
    std::vector<int> sortedUpdate = update;

    auto is_less_than = [&rules](int a, int b) {
        if (rules.count({a, b})) return true;
        if (rules.count({b, a})) return false;
        return a < b;
    };

    std::sort(sortedUpdate.begin(), sortedUpdate.end(),
        [&is_less_than](int x, int y) {
            return is_less_than(x, y);
        });

    if (update == sortedUpdate) {
        return true;
    }
    return false;
}

int part_1(std::string& input) {
    int sum{0};

    // separate rules and updates
    size_t pos{input.find("\n\n")};
    std::string rulesSection{input.substr(0, pos)};
    std::string updatesSection{input.substr(pos + 2)};

    // store rules as std::set
    std::set<std::pair<int, int>> rules{};
    std::stringstream rulesSectionStream(rulesSection);
    std::string rule;

    while (std::getline(rulesSectionStream, rule)) {
        rules.insert(split_rule(rule, '|'));
    }

    // for each vector of updates
    std::stringstream updatesSectionStream(updatesSection);
    std::string update;

    while (std::getline(rulesSectionStream, update)) {
        std::vector<int> updateParsed{split_update(update, ',')};
        if (update_is_correct(updateParsed, rules)) {
            // add middle page to sum
        }
    }

    return sum;
}

int main() {
    // std::string input{read_file("input.txt")};
    std::string input{read_file("test.txt")};

    part_1(input);

    return 0;
}
