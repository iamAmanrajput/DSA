// Leetcode Problem 322. Coin Change
// Time Complexity (TC): O(n^amount)
// Space Complexity (SC): O(amount)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(vector<int> &coins, int amount)
    {

        // Base case: exact amount achieved
        if (amount == 0)
        {
            return 0;
        }

        // If amount becomes negative → invalid path
        if (amount < 0)
        {
            return INT_MAX;
        }

        int mini = INT_MAX;

        // Try every coin
        for (int i = 0; i < coins.size(); i++)
        {

            // Recursive call for remaining amount
            int recAns = solveUsingRecursion(coins, amount - coins[i]);

            // Only consider valid answers
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }

        return mini;
    }

    int coinChange(vector<int> &coins, int amount)
    {

        int ans = solveUsingRecursion(coins, amount);

        // If no solution found, return -1
        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Output: " << obj.coinChange(coins1, amount1) << endl;
    // Expected: 3 (5+5+1)

    // Test Case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Output: " << obj.coinChange(coins2, amount2) << endl;
    // Expected: -1 (not possible)

    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Output: " << obj.coinChange(coins3, amount3) << endl;
    // Expected: 0

    // Test Case 4
    vector<int> coins4 = {2, 5, 10, 1};
    int amount4 = 27;
    cout << "Output: " << obj.coinChange(coins4, amount4) << endl;
    // Example output

    return 0;
}