#include <iostream>
#include <vector>

class Solution {
public:
    int linearSearch(std::vector<int>& nums, int target) {
        // 'nums.size()' ka use vector ka size lene ke liye kiya gaya hai.
        for (int i = 0; i < nums.size(); ++i) {
            // Check karein ki current element 'target' ke barabar hai ya nahi.
            if (nums[i] == target) {
                // Agar mil jaata hai, to uska index return karein.
                return i;
            }
        }
        // Agar loop ke baad bhi target nahi milta, to -1 return karein.
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> myVector = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    int result = sol.linearSearch(myVector, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the vector." << std::endl;
    }

    return 0;
}