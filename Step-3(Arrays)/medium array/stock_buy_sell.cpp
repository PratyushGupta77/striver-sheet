#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max functions

using namespace std;

// This function calculates the maximum possible profit.
// It finds the lowest price to buy a stock and the highest price to sell it on a later day.
int maxProfit(vector<int>& prices) {
    // Agar prices ki list khali hai ya usme sirf ek hi stock price hai,
    // toh koi profit nahi ho sakta.
    if (prices.empty() || prices.size() == 1) {
        return 0;
    }

    // `minPrice` variable ko pehle din ke price se initialize karte hain.
    // Yah hamara buying price hoga.
    int minPrice = prices[0];
    
    // `maxProfit` ko 0 se initialize karte hain.
    // Agar koi profitable transaction nahi hoti, toh profit 0 hi rahega.
    int maxProfit = 0;

    // Loop prices ke vector me dusre din se shuru hota hai (index 1).
    // Hum har din ko selling day maante hain.
    for (int i = 1; i < prices.size(); ++i) {
        // Step 1: `minPrice` ko update karo.
        // `min(minPrice, prices[i])` yeh check karta hai ki ab tak ka sabse kam price
        // ya aaj ka price, dono me se chhota kaun hai.
        minPrice = min(minPrice, prices[i]);

        // Step 2: Aaj bechne par kitna profit hoga, woh calculate karo.
        // Formula hai: (current selling price) - (lowest buying price so far).
        int currentProfit = prices[i] - minPrice;

        // Step 3: `maxProfit` ko update karo.
        // `max(maxProfit, currentProfit)` yeh dekhta hai ki ab tak ka sabse jyada profit
        // ya aaj ka profit, dono me se bada kaun hai.
        maxProfit = max(maxProfit, currentProfit);
    }

    // Aakhir me, final `maxProfit` return kar do.
    return maxProfit;
}

int main() {
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int profit1 = maxProfit(prices1);
    cout << "Example 1:" << endl;
    cout << "Input: [7, 1, 5, 3, 6, 4]" << endl;
    cout << "Maximum Profit: " << profit1 << endl; // Output: 5
    cout << endl;

    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int profit2 = maxProfit(prices2);
    cout << "Example 2:" << endl;
    cout << "Input: [7, 6, 4, 3, 1]" << endl;
    cout << "Maximum Profit: " << profit2 << endl; // Output: 0
    cout << endl;
    
    // Example 3
    vector<int> prices3 = {1, 2};
    int profit3 = maxProfit(prices3);
    cout << "Example 3:" << endl;
    cout << "Input: [1, 2]" << endl;
    cout << "Maximum Profit: " << profit3 << endl; // Output: 1
    
    return 0;
}