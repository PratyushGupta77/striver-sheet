#include <iostream>
#include <vector>
#include <map>

// This line allows you to use `vector`, `cout`, `map`, etc., directly without `std::` prefix.
using namespace std;

// This function finds two numbers in a vector that add up to a target.
// It uses a map to achieve an efficient O(n) time complexity.
vector<int> twoSum(vector<int>& nums, int target) {
    // `seenNumbers` stores the numbers we've seen so far and their indices.
    // The key is the number itself, and the value is its index.
    map<int, int> seenNumbers;
    int n = nums.size();

    // Loop through each number in the input vector.
    for (int i = 0; i < n; i++) {
        int currentNum = nums[i];
        
        // Calculate the "complement" - the number needed to reach the target.
        int complement = target - currentNum;

        // Check if this complement already exists in our map.
        // `find()` returns an iterator to the key if it exists, otherwise it returns `end()`.
        if (seenNumbers.find(complement) != seenNumbers.end()) {
            // If the complement is found, we've found our pair!
            // Return the index of the complement and the current number's index.
            return {seenNumbers[complement], i};
        }

        // If the complement wasn't found, store the current number and its index in the map
        // for future lookups.
        seenNumbers[currentNum] = i;
    }

    // According to the problem statement, a solution is guaranteed to exist.
    // This line is for safety in case no solution is found.
    return {};
}

int main() {
    // Example 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);
    
    cout << "Example 1:" << endl;
    cout << "Input: nums = [2, 7, 11, 15], target = 9" << endl;
    if (!result1.empty()) {
        cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = twoSum(nums2, target2);

    cout << "Example 2:" << endl;
    cout << "Input: nums = [3, 2, 4], target = 6" << endl;
    if (!result2.empty()) {
        cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}