// Leetcode Problem 72. Edit Distance
// Time Complexity (TC): O(n * m)
// - We fill a DP table of size n x m

// Space Complexity (SC): O(n * m)
// - 2D DP array used

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Edit Distance (Leetcode 72)
    Approach (Bottom-Up / Tabulation):
    - Build DP table from bottom-right to top-left
    - Base cases:
        dp[n][j] = remaining characters of b
        dp[i][m] = remaining characters of a
    - If characters match → move diagonally
    - Else take min of insert, delete, replace
*/

class Solution
{
public:
    int minDistance(string &a, string &b)
    {

        int n = a.length();
        int m = b.length();

        // DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base Case: last row
        for (int col = 0; col <= m; col++)
        {
            dp[n][col] = m - col;
        }

        // Base Case: last column
        for (int row = 0; row <= n; row++)
        {
            dp[row][m] = n - row;
        }

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                if (a[i] == b[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    int replace = 1 + dp[i + 1][j + 1];
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][j];

                    dp[i][j] = min(insert, min(remove, replace));
                }
            }
        }

        return dp[0][0];
    }
};

int main()
{
    Solution obj;

    string word1 = "horse";
    string word2 = "ros";

    int result = obj.minDistance(word1, word2);

    cout << "Minimum operations required: " << result << endl;

    // Expected Output: 3

    return 0;
}