#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix;

void initializeMatrix() {
    matrix.push_back({1,2,3,4,5});
    matrix.push_back({6,7,8,9,0});
    matrix.push_back({-1,-2,-3,-4,-5});
    matrix.push_back({-6,-7,-8,-9,0});
    matrix.push_back({11,12,13,14,15});
}

void rotateMatrix() {
    // row 0-4 becomes column 4-0, column 0-4 becomes row 0-4
    unsigned int i = 0, j = 0, x = matrix.size(), y = matrix[0].size();
    for (i = 0; i < x / 2; i++) {
        for (j = 0; j <= y / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][x-i-1];
            matrix[j][x-i-1] = matrix[x-i-1][y-j-1];
            matrix[x-i-1][y-j-1] = matrix[y-j-1][i];
            matrix[y-j-1][i] = temp;
        }
    }
}

int main () {
    initializeMatrix();
    rotateMatrix();
    for (std::vector<int> r: matrix) {
        for (int i: r) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}