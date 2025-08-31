#include <iostream>
#include <vector>
using namespace std;

// Yeh woh class hai jo aap online platform par submit karenge
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge Case: Agar array khaali hai, to 0 unique elements hain.
        if (nums.empty()) {
            return 0;
        }

        // 'i' slow pointer hai, jo unique elements ki aakhri position ko track karta hai.
        int i = 0;

        // 'j' fast pointer hai, jo poore array mein ghoomta hai.
        for (int j = 1; j < nums.size(); j++) {
            
            // Jab 'j' ko 'i' se alag element milta hai...
            if (nums[j] != nums[i]) {
                // ...'i' ko aage badhao...
                i++;
                // ...aur nayi jagah par 'j' ka element daal do.
                nums[i] = nums[j];
            }
        }
        
        // Total unique elements ki ginti i+1 hai.
        return i + 1;
    }
};

// Yeh main function sirf aapke local machine (VS Code) par test karne ke liye hai.
// Online platform par iski zaroorat nahi hoti.
int main() {
    // 1. Ek test array banate hain
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    cout << "Original Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // 2. Solution class ka object banate hain
    Solution sol;
    
    // 3. removeDuplicates function ko call karte hain
    int k = sol.removeDuplicates(nums);
    
    // 4. Result print karte hain
    cout << "Number of unique elements: " << k << endl;
    
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}














// ## Code ka Logic Explained
// int i = 0;: Hamara Writer i pehli unique position (index 0) par taiyaar hai.
// for (int j = 1; ...): Hamara Reader j doosre element se sabko check karna shuru karta hai.
// if (nums[j] != nums[i]): Jab Reader ko naya (unique) number milta hai...
// i++; nums[i] = nums[j];: ...Writer aage badhkar usko apni list mein likh deta hai.
// return i + 1;: Jitni jagah Writer ne li (i tak), wahi hamara unique elements ka count hai.