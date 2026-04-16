// Leetcode Problem 322. Coin Change
// Time Complexity (TC): O(n * amount)
// Space Complexity (SC): O(amount)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp)
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

        // If already computed, return stored value
        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        int mini = INT_MAX;

        // Try all coins
        for (int i = 0; i < coins.size(); i++)
        {

            // Recursive call for remaining amount
            int recAns = solve(coins, amount - coins[i], dp);

            // Only consider valid answers
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }

        // Store result in DP array
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {

        // DP array initialized with -1
        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, dp);

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
    // Expected: -1

    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Output: " << obj.coinChange(coins3, amount3) << endl;
    // Expected: 0

    // Test Case 4
    vector<int> coins4 = {2, 5, 10, 1};
    int amount4 = 27;
    cout << "Output: " << obj.coinChange(coins4, amount4) << endl;

    return 0;
}