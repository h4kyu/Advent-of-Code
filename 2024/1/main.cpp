#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


int part_1(std::vector<int>& col_1, std::vector<int>& col_2) {
    int distance{0};

    std::sort(col_1.begin(), col_1.end());
    std::sort(col_2.begin(), col_2.end());

    // iterate over ith element of col_1, col_2, find abs diff and add to distance
    for(int i{0}; i < col_1.size(); ++i) {
        distance += abs(col_1[i] - col_2[i]);
    }
    return distance;
}

int part_2(std::vector<int>& col_1, std::vector<int>& col_2) {
    int score{0};

    std::sort(col_1.begin(), col_1.end());
    std::sort(col_2.begin(), col_2.end());

    // iterate over ith element of col_1, find count
    for(int i{0}; i < col_1.size(); ++i) {
        score += col_1[i]*(std::count(col_2.begin(), col_2.end(), col_1[i]));
    }
    return score;
}

int main() {
    std::ifstream file("input");
    std::string str;
    if (!file) { // test if file is opened
        return 1;
    }

    std::vector<int> col_1;
    std::vector<int> col_2;
    // parse file into 2 columns of numbers
    int num_1;
    int num_2;
    while(file >> num_1 >> num_2) {
        col_1.push_back(num_1);
        col_2.push_back(num_2);
    }

    // part 1 confirm
    std::cout << part_1(col_1, col_2) << std::endl;
    // part 2 confirm
    std::cout << part_2(col_1, col_2) << std::endl;

    return 0;
}
