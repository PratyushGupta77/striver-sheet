#include <iostream>
#include <vector>
#include <algorithm>

// This is the class where the logic for the union function is defined.
class Solution {
public:
    std::vector<int> unionArray(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        std::vector<int> unionList;

        // Compare elements and add to the union list
        while (i < nums1.size() && j < nums2.size()) {

            // Skip duplicates in nums1
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }

            // Skip duplicates in nums2
            if (j > 0 && nums2[j] == nums2[j - 1]) {
                j++;
                continue;
            }

            if (nums1[i] < nums2[j]) {
                unionList.push_back(nums1[i]);
                i++;
            } else if (nums2[j] < nums1[i]) {
                unionList.push_back(nums2[j]);
                j++;
            } else { // Elements are equal
                unionList.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        // Add remaining elements from nums1
        while (i < nums1.size()) {
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }
            unionList.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < nums2.size()) {
            if (j > 0 && nums2[j] == nums2[j - 1]) {
                j++;
                continue;
            }
            unionList.push_back(nums2[j]);
            j++;
        }

        return unionList;
    }
};

// This is the main function, where the program starts running.
int main() {
    // Create an object of the Solution class.
    Solution solution;

    // Define two example sorted arrays (vectors).
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, 7, 8, 9};

    // Call the function to find the union and store the result.
    std::vector<int> result = solution.unionArray(nums1, nums2);

    // Print the elements of the result vector.
    std::cout << "The union of the two arrays is: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}