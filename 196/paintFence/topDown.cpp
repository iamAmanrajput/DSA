// GFG Problem Painting the Fence
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Recursive + Memoization function
    int solve(int n, int k, vector<int> &dp)
    {

        // Base case: 1 post → k ways
        if (n == 1)
        {
            return k;
        }

        // Base case: 2 posts → k + k*(k-1) = k^2 ways
        if (n == 2)
        {
            return (k + k * (k - 1));
        }

        // If already computed, return stored value
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Recurrence relation
        dp[n] = (solve(n - 1, k, dp) + solve(n - 2, k, dp)) * (k - 1);

        return dp[n];
    }

    // Main function
    int countWays(int n, int k)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, k, dp);
    }
};

/*
Problem:
Given a fence with n posts and k colours, find out the number of ways
of painting the fence so that not more than two consecutive posts
have the same colours.

Constraint:
- No more than 2 consecutive posts can have the same color.
- Answer fits in 32-bit integer.

Approach:
- Use Dynamic Programming (Memoization)
- Recurrence:
    dp[n] = (dp[n-1] + dp[n-2]) * (k-1)
- Base cases:
    dp[1] = k
    dp[2] = k^2
*/

int main()
{
    Solution obj;

    // Test Case 1
    int n1 = 3, k1 = 2;
    cout << "Test Case 1: n = 3, k = 2" << endl;
    cout << "Output: " << obj.countWays(n1, k1) << endl; // Expected: 6

    cout << endl;

    // Test Case 2
    int n2 = 4, k2 = 3;
    cout << "Test Case 2: n = 4, k = 3" << endl;
    cout << "Output: " << obj.countWays(n2, k2) << endl;

    return 0;
}