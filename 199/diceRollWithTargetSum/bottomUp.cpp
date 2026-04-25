// Leetcode Problem 1155. Number of Dice Rolls With Target Sum
/* TC: O(n * target * k)
   We use three nested loops: n dice, target sum, and k faces.

   SC: O(n * target)
   We use a 2D vector of size (n+1) x (target+1).
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long int MOD = 1000000007;

    int numRollsToTarget(int n, int k, int target)
    {
        // Create a DP table where dp[i][j] represents the number of ways
        // to get sum 'j' using 'i' dice.
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base Case: 0 dice can form a sum of 0 in exactly 1 way.
        dp[0][0] = 1;

        // Loop through each die (from 1 to n)
        for (int i = 1; i <= n; i++)
        {
            // Loop through each possible target sum (from 1 to target)
            for (int j = 1; j <= target; j++)
            {
                long long int ans = 0;
                // Try every face value of the current die (from 1 to k)
                for (int idx = 1; idx <= k; idx++)
                {
                    // Check if the current face value 'idx' can be part of the sum 'j'
                    if (j - idx >= 0)
                    {
                        ans = (ans + dp[i - 1][j - idx]) % MOD;
                    };
                }
                dp[i][j] = (int)ans;
            }
        }
        return dp[n][target];
    }
};

int main()
{
    Solution sol;

    // Test Case: n = 3, k = 2, target = 6
    // Only one way to get 6 with 3 dice of 2 faces: (2,2,2)
    int n = 3, k = 2, target = 6;

    int result = sol.numRollsToTarget(n, k, target);

    cout << "Test Case Result (n=3, k=2, target=6): " << result << endl;

    // Another Test Case: n = 2, k = 6, target = 7
    cout << "Test Case Result (n=2, k=6, target=7): " << sol.numRollsToTarget(2, 6, 7) << endl;

    return 0;
}