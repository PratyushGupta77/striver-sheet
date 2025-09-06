#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        // This swaps matrix[i][j] with matrix[j][i].
        // We only iterate through the upper right triangle to avoid double-swapping.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row of the transposed matrix
        // This puts the elements in their correct, final positions for a 90-degree clockwise rotation.
        for (int i = 0; i < n; ++i) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example 1: 3x3 matrix
    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    
    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix1);
    
    sol.rotate(matrix1);
    
    std::cout << "\nMatrix after 90-degree rotation (clockwise):" << std::endl;
    printMatrix(matrix1);
    // Expected Output:
    // 7 4 1
    // 8 5 2
    // 9 6 3
    
    std::cout << "----------------------" << std::endl;

    // Example 2: 4x4 matrix
    std::vector<std::vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    
    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix2);
    
    sol.rotate(matrix2);

    std::cout << "\nMatrix after 90-degree rotation (clockwise):" << std::endl;
    printMatrix(matrix2);
    // Expected Output:
    // 15 13 2 5
    // 14 3 4 1
    // 12 6 8 9
    // 16 7 10 11

    return 0;
}