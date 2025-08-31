#include <iostream>
#include <vector>
#include <limits.h> // INT_MIN ko use karne ke liye
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        // Edge case: Agar array mein 2 se kam elements hain
        if (nums.size() < 2) {
            return -1;
        }

        // Array ke har element ko check karne ke liye loop
        for (int i = 0; i < nums.size(); i++) {
            // Agar current element sabse bada hai
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
            }
            // Agar current element largest se chota hai,
            // lekin secondLargest se bada hai
            else if (nums[i] < largest && nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }
        
        // **YEH PART MISSING THA**
        // Agar secondLargest kabhi update hi nahi hua, to -1 return karo
        if (secondLargest == INT_MIN) {
            return -1;
        }

        return secondLargest;
    }
};

// **YEH MAIN FUNCTION MISSING THA**
int main() {
    // 1. Test karne ke liye ek array banaya
    vector<int> arr = {8, 6, 7, 5};

    // 2. Aapki Solution class ka ek object banaya
    Solution sol;

    // 3. Aapke function ko call karke result store kiya
    int result = sol.secondLargestElement(arr);

    // 4. Result ko screen par print kiya
    cout << "The second largest element is: " << result << endl;

    return 0; // Program successfully khatam hua
}