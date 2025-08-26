#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        // Pointer 'j' keeps track of the next position for a non-zero element.
        // It's like a bookmark for where the "clean" part of the array ends.
        int j = 0; 
        
        // Pointer 'i' iterates through every element of the entire array.
        for (int i = 0; i < nums.size(); ++i) {
            // If the element at the current position 'i' is NOT a zero...
            if (nums[i] != 0) {
                // ...we swap it with the element at position 'j'.
                // This moves the non-zero number to the front section of the array.
                std::swap(nums[i], nums[j]);
                
                // Then, we increment 'j' to move the bookmark forward,
                // ready for the next non-zero number.
                j++;
            }
        }
    }
};

int main() {
    // Create an instance of the Solution class to use the function.
    Solution sol;
    
    // Initialize a sample vector with some zeroes.
    std::vector<int> arr = {0, 1, 0, 3, 12};
    
    // Print the original vector to see the starting state.
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Call the function to move the zeroes.
    sol.moveZeroes(arr);
    
    // Print the modified vector to see the final result.
    std::cout << "Modified array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Return 0 to indicate successful program execution.
    return 0;
}