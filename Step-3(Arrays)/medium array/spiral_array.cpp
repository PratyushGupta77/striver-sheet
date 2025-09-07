#include <iostream>
#include <vector>

void printSpiral(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Print top row from left to right
        for (int j = left; j <= right; ++j) {
            std::cout << matrix[top][j] << " ";
        }
        top++;

        // Print right column from top to bottom
        for (int i = top; i <= bottom; ++i) {
            std::cout << matrix[i][right] << " ";
        }
        right--;

        // Print bottom row from right to left
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                std::cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        // Print left column from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                std::cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main() {
    // Example 1: A 3x3 matrix
    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << "Printing matrix1 in spiral order:\n";
    printSpiral(matrix1);
    std::cout << "\n\n";

    // Example 2: A non-square 3x4 matrix
    std::vector<std::vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    std::cout << "Printing matrix2 in spiral order:\n";
    printSpiral(matrix2);
    std::cout << "\n";

    return 0;
}