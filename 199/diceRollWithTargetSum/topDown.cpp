// Leetcode Problem 1155. Number of Dice Rolls With Target Sum
/* TC: O(n * target * k)
   Each state (n, target) is computed once, and each state takes O(k) time.

   SC: O(n * target)
   Due to the 2D DP table and recursion stack depth O(n).
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long int MOD = 1000000007;

    // Helper function using recursion + memoization
    int solve(int n, int &k, int target, vector<vector<int>> &dp)
    {
        // Base Case: If no dice left and target is reached
        if (target == 0 && n == 0)
        {
            return 1;
        }
        // Base Case: If no dice left but target not reached
        if (target != 0 && n == 0)
        {
            return 0;
        }
        // Base Case: If target is 0 but dice are still left
        if (target == 0 && n != 0)
        {
            return 0;
        }

        // Memoization check
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        };

        int ans = 0;
        // Try every face of the die from 1 to k
        for (int i = 1; i <= k; i++)
        {
            int recAns = 0;
            if (target - i >= 0)
            {
                recAns = solve(n - 1, k, target - i, dp) % MOD;
                ans = ((ans % MOD) + (recAns % MOD)) % MOD;
            };
        }

        // Store the result in dp table
        dp[n][target] = ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solve(n, k, target, dp);
        return ans;
    }
};

int main()
{
    Solution sol;

    // Test Case: n = 2, k = 6, target = 7
    // Possible outcomes: (1,6), (2,5), (3,4), (4,3), (5,2), (6,1) -> Total 6
    int n = 2, k = 6, target = 7;

    int result = sol.numRollsToTarget(n, k, target);

    cout << "Number of dice rolls to reach target: " << result << endl;

    return 0;
}