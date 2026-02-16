#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

void fillMatrix(std::vector<std::vector<int>>& matrix, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(5) << val;
        }
        std::cout << std::endl;
    }
}

void transposeMatrixIterative(std::vector<std::vector<int>>& matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    srand(time(0));
    const int n = 4;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    fillMatrix(matrix, n, 1, 50);

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);

    transposeMatrixIterative(matrix, n);

    std::cout << "\nTransposed Matrix:" << std::endl;
    printMatrix(matrix);

    return 0;
}