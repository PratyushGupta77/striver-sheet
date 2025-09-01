#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};

int main() {
    // Test case 1 from LeetCode
    std::vector<int> nums1 = {3, 2, 3};
    Solution sol;
    int result1 = sol.majorityElement(nums1);
    std::cout << "The majority element for {3, 2, 3} is: " << result1 << std::endl; // Expected output: 3

    // Test case 2 from LeetCode
    std::vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    int result2 = sol.majorityElement(nums2);
    std::cout << "The majority element for {2, 2, 1, 1, 1, 2, 2} is: " << result2 << std::endl; // Expected output: 2

    return 0;
}