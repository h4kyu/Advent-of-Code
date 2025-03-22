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

    // size_t searchStart{0};
    size_t searchStart{input.find(delimiter)};

    while (searchStart != std::string::npos) {

        // check if ')' exists within 8 characters
        std::string toSearch{input.substr(searchStart + delimiter.size(), 8)}; // maximum of 8 characters between '(' and ')' inclusive
        size_t pos{toSearch.find(')')}; // zero based index

        if (pos != std::string::npos) {
            // search for comma until ')' pos
            toSearch = toSearch.substr(0, pos); // substr of chars btw '(' and ')'

            if (toSearch.find(',') != std::string::npos) {
                // check if only numbers exist between comma position and '(' and ')'
                std::string leftOfComma{toSearch.substr(0, toSearch.find(','))};
                std::string rightOfComma{toSearch.substr(toSearch.find(',') + 1)};

                if (!leftOfComma.empty() && std::all_of(leftOfComma.begin(), leftOfComma.end(), ::isdigit)
                    && !rightOfComma.empty() && std::all_of(rightOfComma.begin(), rightOfComma.end(), ::isdigit)) {
                    mulSum += std::stoi(leftOfComma)*std::stoi(rightOfComma);
                }
            }
        }

        // update search area
        // searchStart = searchEnd + 4;
        searchStart = input.find(delimiter, searchStart + delimiter.size());

    }
    return mulSum;
}

/* default bool enabled as true. same procedure as part_1, except add an extra step to check state of enabled.
 * store last position of mul( and search for 'don't()' and 'do()' in between.
 * compare indices and change enabled accordingly.
*/


int part_2(std::string& input) {
    bool enabled{true};
    int mulSum{0};
    const std::string delimiter{"mul("};

    size_t prevStart{0};
    size_t searchStart{input.find(delimiter)};

    while (searchStart != std::string::npos) {

        std::string toSearchEnabled{input.substr(prevStart, searchStart - prevStart)};
        size_t posDo{toSearchEnabled.find("do()")};
        size_t posDont{toSearchEnabled.find("don't()")};

        if (posDo != std::string::npos && posDont != std::string::npos && posDo > posDont) { // do() exists and is after don't()
            enabled = true;
        } else if (posDo != std::string::npos && posDont == std::string::npos) {
            enabled = true;
        } else if (posDont != std::string::npos && posDo != std::string::npos && posDont > posDo) {
            enabled = false;
            prevStart = searchStart;
            searchStart = input.find(delimiter, searchStart + delimiter.size());
            continue;
        } else if (posDont != std::string::npos && posDo == std::string::npos) {
            enabled = false;
            prevStart = searchStart;
            searchStart = input.find(delimiter, searchStart + delimiter.size());
            continue;
        }

        // check if ')' exists within 8 characters
        std::string toSearch{input.substr(searchStart + delimiter.size(), 8)}; // maximum of 8 characters between '(' and ')' inclusive
        size_t pos{toSearch.find(')')}; // zero based index

        if (pos != std::string::npos) {
            // search for comma until ')' pos
            toSearch = toSearch.substr(0, pos); // substr of chars btw '(' and ')'

            if (toSearch.find(',') != std::string::npos) {
                // check if only numbers exist between comma position and '(' and ')'
                std::string leftOfComma{toSearch.substr(0, toSearch.find(','))};
                std::string rightOfComma{toSearch.substr(toSearch.find(',') + 1)};

                if (!leftOfComma.empty() && std::all_of(leftOfComma.begin(), leftOfComma.end(), ::isdigit)
                    && !rightOfComma.empty() && std::all_of(rightOfComma.begin(), rightOfComma.end(), ::isdigit)) {
                    mulSum += std::stoi(leftOfComma)*std::stoi(rightOfComma);
                    }
            }
        }

        // update search area
        // searchStart = searchEnd + 4;
        searchStart = input.find(delimiter, searchStart + delimiter.size());

    }
    return mulSum;
}


int main() {
    // read file into string input
    std::ifstream file("input.txt");
    std::string input{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    // std::ifstream file("test.txt");
    // std::string input{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    std::cout << part_1(input) << std::endl;
    return 0;
}
