// Leetcode Problem 72. Edit Distance
// Time Complexity (TC): O(n * m)
// - Each state (i, j) is computed only once due to memoization

// Space Complexity (SC): O(n * m) + O(n + m)
// - O(n * m) for dp array
// - O(n + m) recursion stack in worst case

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Edit Distance (Leetcode 72)
    Approach:
    - If characters match, move both pointers
    - Else try 3 operations:
        1. Insert
        2. Delete
        3. Replace
    - Take minimum of all
*/

class Solution
{
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {

        // Base Case 1: 'a' finished, insert remaining characters of 'b'
        if (i == a.length())
        {
            return b.length() - j;
        }

        // Base Case 2: 'b' finished, delete remaining characters of 'a'
        if (j == b.length())
        {
            return a.length() - i;
        }

        // Check DP
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;

        // If characters match
        if (a[i] == b[j])
        {
            ans = solve(a, b, i + 1, j + 1, dp);
        }
        else
        {
            // Replace
            int replace = 1 + solve(a, b, i + 1, j + 1, dp);

            // Insert
            int insert = 1 + solve(a, b, i, j + 1, dp);

            // Delete
            int remove = 1 + solve(a, b, i + 1, j, dp);

            ans = min(insert, min(remove, replace));
        }

        // Store result in DP
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2)
    {

        // DP array initialization with -1
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));

        return solve(word1, word2, 0, 0, dp);
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