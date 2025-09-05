#include <iostream>
#include <vector>

// Function to find the count of subarrays with a given sum
int subarraySum(std::vector<int>& nums, int k) {
    int count = 0; // Initialize a counter for subarrays

    // Outer loop to select the starting point of the subarray
    for (int i = 0; i < nums.size(); ++i) {
        int currentSum = 0; // Reset sum for each new subarray starting at 'i'
        
        // Inner loop to select the ending point of the subarray
        for (int j = i; j < nums.size(); ++j) {
            currentSum += nums[j]; // Add the next element to the current sum
            
            // Check if the current subarray's sum equals k
            if (currentSum == k) {
                count++; // If it does, increment the counter
            }
        }
    }
    return count; // Return the final count
}

int main() {
    // Example 1
    std::vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    int result1 = subarraySum(nums1, k1);
    std::cout << "For nums = {1, 1, 1} and k = 2, the count is: " << result1 << std::endl; // Output: 2

    // Example 2
    std::vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    int result2 = subarraySum(nums2, k2);
    std::cout << "For nums = {1, 2, 3} and k = 3, the count is: " << result2 << std::endl; // Output: 2

    return 0;
}