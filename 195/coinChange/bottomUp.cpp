// Leetcode Problem 322. Coin Change
// Time Complexity (TC): O(n * amount)
// Space Complexity (SC): O(amount)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        // Step 1: DP array initialize with INT_MAX
        vector<int> dp(amount + 1, INT_MAX);

        // Step 2: Base case
        dp[0] = 0;

        // Step 3: Build answer from 1 → amount
        for (int value = 1; value <= amount; value++)
        {

            int mini = INT_MAX; // minimum coins needed for current value

            // Try every coin
            for (int i = 0; i < coins.size(); i++)
            {

                // Check valid index and avoid overflow
                if (value - coins[i] >= 0 && dp[value - coins[i]] != INT_MAX)
                {

                    int ans = 1 + dp[value - coins[i]];
                    mini = min(mini, ans);
                }
            }

            // Store result in DP array
            dp[value] = mini;
        }

        // If not possible to make amount
        if (dp[amount] == INT_MAX)
        {
            return -1;
        }

        return dp[amount];
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Output: " << obj.coinChange(coins1, amount1) << endl;
    // Expected: 3 (5 + 5 + 1)

    // Test Case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Output: " << obj.coinChange(coins2, amount2) << endl;
    // Expected: -1

    // Test Case 3 (minimum case)
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