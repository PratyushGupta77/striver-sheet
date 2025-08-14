// BUBBLE SORT
// bubble sort ka bas ek hi rule hai pass waale element ko compare karo aur agr woh galat order main hai toh unha exchange karo

// -hr round mai sabsa bada unsorted element bubble ki tyarah upar uth kar apni sahi jagah par end mein aa jata hai
// -agle round mein uss sorted element ko chodkr baaki sab par yeh process repeat hota __has_include-
// -yeh tab tak chalta hai jab tak poora aaray sort na hi jaaye


#include <iostream>
#include <vector>
#include <utility> // Required for std::swap

// Function to print the elements of a vector
void printArray(const std::vector<int>& arr) {
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// The Optimized Bubble Sort function
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Outer loop for passes
    for (int i = 0; i < n - 1; ++i) {
        swapped = false; // Har naye pass ke shuru mein flag ko reset karo

        // Inner loop for comparison and swapping
        // '-i' is an optimization so we don't check the already sorted part
        for (int j = 0; j < n - i - 1; ++j) {
            // Agar element galat order mein hai
            if (arr[j] > arr[j + 1]) {
                // Toh unhe swap karo
                std::swap(arr[j], arr[j + 1]);
                swapped = true; // Mark karo ki swap hua hai
            }
        }

        // Agar is poore pass mein koi swap nahi hua,
        // iska matlab array sorted hai. Loop tod do.
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);

    std::cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}