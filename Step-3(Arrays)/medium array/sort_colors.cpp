#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Original array: ";
    printVector(nums1);
    sortColors(nums1);
    cout << "Sorted array:   ";
    printVector(nums1);
    cout << endl;

    // Example 2
    vector<int> nums2 = {2, 0, 1};
    cout << "Original array: ";
    printVector(nums2);
    sortColors(nums2);
    cout << "Sorted array:   ";
    printVector(nums2);

    return 0;
}