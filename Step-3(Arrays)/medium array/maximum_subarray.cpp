#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxi = INT_MIN;
        int current_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];

            if (current_sum > maxi) {
                maxi = current_sum;
            }

            if (current_sum < 0) {
                current_sum = 0;
            }
        }

        // Edge case for when all numbers are negative, the largest negative number is the answer.
        // My previous code has a small bug with this case.
        if (maxi == 0 && nums.size() > 1) {
            bool all_negative = true;
            for (int num : nums) {
                if (num >= 0) {
                    all_negative = false;
                    break;
                }
            }
            if (all_negative) {
                maxi = INT_MIN;
                for (int num : nums) {
                    if (num > maxi) {
                        maxi = num;
                    }
                }
            }
        }

        return maxi;
    }
};

int main() {
    Solution sol;

    // Test case 1
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "The maximum subarray sum for {-2, 1, -3, 4, -1, 2, 1, -5, 4} is: " << sol.maxSubArray(nums1) << std::endl;

    // Test case 2
    std::vector<int> nums2 = {1};
    std::cout << "The maximum subarray sum for {1} is: " << sol.maxSubArray(nums2) << std::endl;

    // Test case 3: All negative numbers
    std::vector<int> nums3 = {-1, -2, -3, -4};
    std::cout << "The maximum subarray sum for {-1, -2, -3, -4} is: " << sol.maxSubArray(nums3) << std::endl;

    // Test case 4: Single negative number
    std::vector<int> nums4 = {-5};
    std::cout << "The maximum subarray sum for {-5} is: " << sol.maxSubArray(nums4) << std::endl;

    return 0;
}