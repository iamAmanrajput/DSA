// GFG Problem Painting the Fence
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countWays(int n, int k)
    {

        // DP array where dp[i] = number of ways to paint i posts
        vector<int> dp(n + 1, -1);

        // Base case:
        // 1 post → k ways
        dp[1] = k;

        // 2 posts → k + k*(k-1) = k^2 ways
        dp[2] = (k + k * (k - 1));

        // Fill DP array from 3 to n
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
        }

        return dp[n];
    }
};

/*
Problem:
Given a fence with n posts and k colours, find out the number of ways
of painting the fence so that not more than two consecutive posts
have the same colours.

Approach:
- Use Bottom-Up Dynamic Programming (Tabulation)
- Recurrence:
    dp[i] = (dp[i-1] + dp[i-2]) * (k-1)
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