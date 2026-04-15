// GFG Problem Maximize the Cut Segments
// Using Dp Technique

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive + Memoization function
    int solve(int n, int x, int y, int z, vector<int> &dp)
    {

        // Base case: exact length achieved
        if (n == 0)
            return 0;

        // Base case: invalid (negative length)
        if (n < 0)
            return INT_MIN;

        // If already computed, return stored value
        if (dp[n] != INT_MIN)
        {
            return dp[n];
        }

        // Try all 3 possible cuts
        int opt1 = 1 + solve(n - x, x, y, z, dp);
        int opt2 = 1 + solve(n - y, x, y, z, dp);
        int opt3 = 1 + solve(n - z, x, y, z, dp);

        // Store the maximum result
        dp[n] = max(opt1, max(opt2, opt3));
        return dp[n];
    }

    // Function to maximize cuts
    int maximizeTheCuts(int n, int x, int y, int z)
    {

        // DP array initialized with INT_MIN (means not computed)
        vector<int> dp(n + 1, INT_MIN);

        // Get answer using recursion + memoization
        int ans = solve(n, x, y, z, dp);

        // If no valid cuts possible, return 0
        return ans < 0 ? 0 : ans;
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    int n1 = 4, x1 = 2, y1 = 1, z1 = 1;
    cout << "Test Case 1 Output: "
         << obj.maximizeTheCuts(n1, x1, y1, z1) << endl;

    // Test Case 2
    int n2 = 5, x2 = 4, y2 = 2, z2 = 6;
    cout << "Test Case 2 Output: "
         << obj.maximizeTheCuts(n2, x2, y2, z2) << endl;

    return 0;
}