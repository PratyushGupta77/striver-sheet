#include <iostream>
#include <vector>

// Function to print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Use two boolean variables to track if the first row or first column needs to be zeroed out
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Step 1: Check if the first row has any zeros
        for (int j = 0; j < cols; ++j) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Step 2: Check if the first column has any zeros
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // Step 3: Use the first row and column as markers
        // Iterate through the rest of the matrix (from index 1,1)
        // If an element is zero, mark its corresponding first row and first column cells as zero
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Step 4: Zero out rows based on markers
        // If a cell in the first column is 0, zero out its entire row
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Step 5: Zero out columns based on markers
        // If a cell in the first row is 0, zero out its entire column
        for (int j = 1; j < cols; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Step 6: Zero out the first row and column if they originally contained a zero
        if (firstRowZero) {
            for (int j = 0; j < cols; ++j) {
                matrix[0][j] = 0;
            }
        }
        
        if (firstColZero) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    // Example 1
    std::vector<std::vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    std::cout << "Original Matrix 1:" << std::endl;
    printMatrix(matrix1);
    
    Solution sol;
    sol.setZeroes(matrix1);
    
    std::cout << "\nMatrix 1 after setting zeroes:" << std::endl;
    printMatrix(matrix1);
    
    std::cout << "\n----------------------------\n" << std::endl;
    
    // Example 2
    std::vector<std::vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    
    std::cout << "Original Matrix 2:" << std::endl;
    printMatrix(matrix2);
    
    sol.setZeroes(matrix2);
    
    std::cout << "\nMatrix 2 after setting zeroes:" << std::endl;
    printMatrix(matrix2);
    
    return 0;
}