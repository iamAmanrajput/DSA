// Leetcode Problem 1143. Longest Common Subsequence

/*
Time Complexity (TC): O(n * m)
-> Har state (i, j) ek baar compute hoti hai due to memoization

Space Complexity (SC): O(n * m) + O(n + m)
-> O(n*m) for dp array
-> O(n+m) recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive + Memoization function to find LCS
    int solve(string &text1, string &text2, int i, int j,
              vector<vector<int>> &dp)
    {

        // Base Case:
        // Agar kisi bhi string ka end aa gaya -> no subsequence possible
        if (i >= text1.length())
        {
            return 0;
        }

        if (j >= text2.length())
        {
            return 0;
        }

        // Agar already compute ho chuka hai
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;

        // Case 1: Characters match
        if (text1[i] == text2[j])
        {
            // Include character and move both pointers
            ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
        }
        else
        {
            // Case 2: Characters do not match
            // Skip one character at a time and take max
            ans = max(
                solve(text1, text2, i, j + 1, dp), // skip from text2
                solve(text1, text2, i + 1, j, dp)  // skip from text1
            );
        }

        // Store result in dp
        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        // DP array initialize with -1
        vector<vector<int>> dp(text1.length() + 1,
                               vector<int>(text2.length() + 1, -1));

        // Start from index 0,0
        return solve(text1, text2, 0, 0, dp);
    }
};

// Main function with test case
int main()
{
    Solution obj;

    // Test Case
    string text1 = "abcde";
    string text2 = "ace";

    int result = obj.longestCommonSubsequence(text1, text2);

    // Output
    cout << "LCS Length: " << result << endl;

    return 0;
}