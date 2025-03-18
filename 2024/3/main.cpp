#include <iostream>
#include <fstream>

/* find all instances of 'mul('
 * for each instance, check if valid:
 *  check if ')' exists within 8 characters inclusive
 *      yes -->
 *      check for comma: if exists, split starting from position after '(' on the left and before ')' on the right
 *          --> check if only numbers exist in those regions, if yes, cast as ints and multiply, add to sum
*/

int part_1(std::string& input) {
    int mulSum{0};
    const std::string delimiter{"mul("};

    size_t searchStart{0};
    size_t searchEnd{input.find(delimiter)};

    while (searchEnd != std::string::npos) {

        // check if ')' exists within 8 characters
        std::string toSearch{input.substr(searchEnd + 4, searchEnd + 12)};
        size_t pos{toSearch.find(')')};

        if (pos != std::string::npos) {
            // search for comma until ')' pos
            toSearch = toSearch.substr(0, pos + 1);

            if (toSearch.find(',') != std::string::npos) {
                // check if only numbers exist between comma position and '(' and ')'
                std::string leftOfComma{toSearch.substr(0, toSearch.find(','))};
                std::string rightOfComma{toSearch.substr(toSearch.find(','))};

                if (!leftOfComma.empty() && std::all_of(leftOfComma.begin(), leftOfComma.end(), ::isdigit)
                    && !rightOfComma.empty() && std::all_of(rightOfComma.begin(), rightOfComma.end(), ::isdigit)) {
                    mulSum += std::stoi(leftOfComma)*std::stoi(rightOfComma);
                }
            }
        }

        // update search area
        searchStart = searchEnd + 4;
        searchEnd = input.find(delimiter, searchEnd);

    }
    return mulSum;
}


int main() {
    // read file into string input
    // std::ifstream file("input.txt");
    // std::string input{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    std::ifstream file("test.txt");
    std::string input{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    std::cout << part_1(input) << std::endl;
    return 0;
}
