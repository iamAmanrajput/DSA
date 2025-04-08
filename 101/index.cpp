// Best Time to Buy & Sell Stocks -- Leetcode
// # iterative approach

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        int i = 0;
        while (i < prices.size())
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }
            i++;
        }

        return maxProfit;
    }
};

int main()
{
    // Sample test case: prices = [7,1,5,3,6,4]
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Create object of Solution class
    Solution sol;

    // Call the function and store result
    int profit = sol.maxProfit(prices);

    // Print the result
    cout << "Maximum Profit: " << profit << endl;

    return 0;
}
