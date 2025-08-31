
#include<bits/stdc++.h>

using namespace std;
void solve(int arr[], int n) {
  int temp = arr[0]; // storing the first element of array in a variable
  for (int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[n - 1] = temp; // assigned the value of variable at the last index
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

}
int main() {
  int n=5;
  
  int arr[]= {1,2,3,4,5};
  solve(arr, n);
}





// notes
// esma kuch nhi khas kara pehla humna temp mai first element ko store karaya hai 
// then saara bacha hua element mai for loop chlakar unko aga shift kardia and last mai temp wala elemnet ko daal dia 


// n normalisation
// n short, k = k % n; is a normalization step that makes sure k is always in the range [0, n-1].
// This is important because rotating an array n times brings it back to its original state. So, rotating by k is the same as rotating by k % n.
// This step handles all cases where k is large or a multiple of n, saving computation and making the code correct for any non-negative k.