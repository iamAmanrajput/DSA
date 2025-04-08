// Best Time to Buy & Sell Stocks -- Leetcode
// # Recursive approach

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to calculate max profit
void calculateProfit(vector<int> &prices, int &minPrice, int &maxProfit, int index)
{
    if (index == prices.size())
    {
        return;
    }

    if (minPrice > prices[index])
    {
        minPrice = prices[index];
    }

    if (prices[index] - minPrice > maxProfit)
    {
        maxProfit = prices[index] - minPrice;
    }

    calculateProfit(prices, minPrice, maxProfit, index + 1);
}

// Main driver function
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Sample input

    int minPrice = INT_MAX;
    int maxProfit = 0;
    int index = 0;

    calculateProfit(prices, minPrice, maxProfit, index);

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
