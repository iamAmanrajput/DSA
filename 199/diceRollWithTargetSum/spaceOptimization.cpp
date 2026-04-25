// Leetcode Problem 1155. Number of Dice Rolls With Target Sum
/* TC (Time Complexity): O(n * target * k)
   We have three nested loops iterating over n, target, and k.

   SC (Space Complexity): O(target)
   We only maintain two vectors of size (target + 1).
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long int MOD = 1000000007;

    int numRollsToTarget(int n, int k, int target)
    {
        // Space optimization: Use only two rows (prev and curr) instead of a 2D matrix
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        // Base case: To get a sum of 0 with 0 dice, there is 1 way.
        prev[0] = 1;

        // Loop through the number of dice
        for (int i = 1; i <= n; i++)
        {
            // Reset curr for the current die so old values don't interfere
            fill(curr.begin(), curr.end(), 0);

            // Loop through each possible target sum
            for (int j = 1; j <= target; j++)
            {
                int ans = 0;
                // Loop through each face of the current die
                for (int idx = 1; idx <= k; idx++)
                {
                    if (j - idx >= 0)
                    {
                        // Current state depends only on the previous die's results
                        ans = (ans + prev[j - idx]) % (int)MOD;
                    };
                }
                curr[j] = ans;
            }
            // Move current results to prev for the next die iteration
            prev = curr;
        }
        return prev[target];
    }
};

int main()
{
    Solution sol;

    // Test Case: n = 2 dice, k = 6 faces, target sum = 7
    // Possible outcomes: (1,6), (2,5), (3,4), (4,3), (5,2), (6,1)
    int n = 2, k = 6, target = 7;

    int result = sol.numRollsToTarget(n, k, target);

    cout << "Test Case Result:" << endl;
    cout << "Dice (n): " << n << ", Faces (k): " << k << ", Target: " << target << endl;
    cout << "Total ways: " << result << endl;

    return 0;
}