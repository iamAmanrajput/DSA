// Leetcode Problem 1143. Longest Common Subsequence
/*
dp[i][j] = LCS length of substring text1[i...end] and text2[j...end]

Time Complexity: O(n * m)
Space Complexity: O(n * m)
where n = text1.length(), m = text2.length()
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        vector<vector<int>> dp(text1.length() + 1,
                               vector<int>(text2.length() + 1, 0));

        // Bottom-up DP (reverse filling)
        for (int i = text1.length() - 1; i >= 0; i--)
        {
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                // Case 1: Characters match
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                // Case 2: Characters do not match
                else
                {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        // Final answer stored at dp[0][0]
        return dp[0][0];
    }
};

int main()
{
    Solution obj;

    // ===============================
    // Test Case 1 (Basic match)
    // ===============================
    string text1 = "abcde";
    string text2 = "ace";
    // Expected Output: 3  (LCS = "ace")

    cout << "Test Case 1 Output: "
         << obj.longestCommonSubsequence(text1, text2) << endl;

    // ===============================
    // Test Case 2 (Exact same strings)
    // ===============================
    string t1 = "abc";
    string t2 = "abc";
    // Expected Output: 3

    cout << "Test Case 2 Output: "
         << obj.longestCommonSubsequence(t1, t2) << endl;

    // ===============================
    // Test Case 3 (No common subsequence)
    // ===============================
    string t3 = "abc";
    string t4 = "def";
    // Expected Output: 0

    cout << "Test Case 3 Output: "
         << obj.longestCommonSubsequence(t3, t4) << endl;

    // ===============================
    // Test Case 4 (Classic example)
    // ===============================
    string t5 = "AGGTAB";
    string t6 = "GXTXAYB";
    // Expected Output: 4  (LCS = "GTAB")

    cout << "Test Case 4 Output: "
         << obj.longestCommonSubsequence(t5, t6) << endl;

    return 0;
}