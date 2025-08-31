#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotateArray(std::vector<int>& nums, int k) {
        int n = nums.size();

        // Handle edge case for an empty or single-element array.
        if (n <= 1) {
            return;
        }

        // Normalize k to be within the array's bounds.
        k = k % n;
        
        // If k is 0 after normalization, no rotation is needed.
        if (k == 0) {
            return;
        }

        // Step 1: Reverse the first k elements.
        std::reverse(nums.begin(), nums.begin() + k);

        // Step 2: Reverse the remaining (n-k) elements.
        std::reverse(nums.begin() + k, nums.end());

        // Step 3: Reverse the entire array.
        std::reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution sol;
    
    // Example 1
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    int k1 = 2;
    sol.rotateArray(nums1, k1);
    
    std::cout << "Example 1 Output: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Expected: 3 4 5 6 1 2

    // Example 2
    std::vector<int> nums2 = {3, 4, 1, 5, 3, 5};
    int k2 = 8;
    sol.rotateArray(nums2, k2);
    
    std::cout << "Example 2 Output: ";
    for (int num : nums2) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Expected: 1 5 3 5 3 4

    return 0;
}


// notes

// normalisation
// In short, k = k % n; is a normalization step that makes sure k is always in the range [0, n-1].
// This is important because rotating an array n times brings it back to its original state. So, rotating by k is the same as rotating by k % n.
// This step handles all cases where k is large or a multiple of n, saving computation and making the code correct for any non-negative k.


// // Let's consider an array split into two parts, A and B.
// Original Array: [A][B]
// Goal (Right Rotation by k): [B][A]
// Goal (Left Rotation by k): [B][A]
// The reversal method cleverly achieves this re-arrangement:
// Reverse A and B: First, you reverse each of the two sub-parts individually.
// [A_rev][B_rev]
// Reverse the Entire Array: Next, you reverse the entire array.
// Reversing [A_rev][B_rev] gives you [B][A].
// This three-step process is a powerful trick because it performs the rotation in-place (without using extra space) and in O(n) time, which is optimal.



// step 1: Reverse the first k elements
// std::reverse(nums.begin(), nums.begin() + k);

// Step 2: Reverse the remaining n-k elements
// std::reverse(nums.begin() + k, nums.end());

// Step 3: Reverse the entire array
// std::reverse(nums.begin(), nums.end());