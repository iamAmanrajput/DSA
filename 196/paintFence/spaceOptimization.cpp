// // GFG Problem Painting the Fence
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

class Solution
{
public:
    int countWays(int n, int k)
    {

        // Base case: 1 post → k ways
        if (n == 1)
        {
            return k;
        }

        // Base case: 2 posts → k^2 ways
        if (n == 2)
        {
            return (k + k * (k - 1));
        }

        // prev2 = dp[i-2], prev1 = dp[i-1]
        int prev2 = k;                 // dp[1]
        int prev1 = (k + k * (k - 1)); // dp[2]
        int curr;

        // Build solution from i = 3 to n
        for (int i = 3; i <= n; i++)
        {
            curr = (prev1 + prev2) * (k - 1);

            // Shift values
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

/*
Problem:
Given a fence with n posts and k colours, find out the number of ways
of painting the fence so that not more than two consecutive posts
have the same colours.

Approach:
- Space Optimized Dynamic Programming
- Recurrence:
    dp[i] = (dp[i-1] + dp[i-2]) * (k-1)
- Base cases:
    dp[1] = k
    dp[2] = k^2

Optimization:
- Instead of using full DP array, we only keep track of last two values
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