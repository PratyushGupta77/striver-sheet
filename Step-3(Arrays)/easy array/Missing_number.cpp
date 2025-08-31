#include <iostream>
#include <vector>
#include <numeric> // Required for std::accumulate

int main() {
    // Example 1
    std::vector<int> nums1 = {3, 0, 1};
    int n1 = nums1.size();
    int expectedSum1 = n1 * (n1 + 1) / 2;
    int actualSum1 = 0;

    for (int num : nums1) {
        actualSum1 += num;
    }
    int missingNumber1 = expectedSum1 - actualSum1;
    std::cout << "Missing number for {3, 0, 1} is: " << missingNumber1 << std::endl; // Output: 2

    // Example 2
    std::vector<int> nums2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int n2 = nums2.size();
    int expectedSum2 = n2 * (n2 + 1) / 2;
    int actualSum2 = 0;

    for (int num : nums2) {
        actualSum2 += num;
    }
    int missingNumber2 = expectedSum2 - actualSum2;
    std::cout << "Missing number for {9, 6, 4, 2, 3, 5, 7, 0, 1} is: " << missingNumber2 << std::endl; // Output: 8

    return 0;
}