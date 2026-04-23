// Leetcode Problem 1143. Longest Common Subsequence

/*
Space Optimized DP (1D)

dp relation:
if match -> 1 + dp[i+1][j+1]
else      -> max(dp[i+1][j], dp[i][j+1])

Optimization:
- next[]  -> represents dp[i+1][*] (next row)
- curr[]  -> represents dp[i][*]   (current row)

Time Complexity: O(n * m)
Space Complexity: O(n)
where n = text1.length(), m = text2.length()
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        vector<int> curr(text1.length() + 1, 0);
        vector<int> next(text1.length() + 1, 0);

        // Traverse text2 (columns)
        for (int j = text2.length() - 1; j >= 0; j--)
        {

            // Traverse text1 (rows)
            for (int i = text1.length() - 1; i >= 0; i--)
            {

                if (text1[i] == text2[j])
                {
                    curr[i] = 1 + next[i + 1];
                }
                else
                {
                    curr[i] = max(next[i], curr[i + 1]);
                }
            }

            // Move current row to next row
            next = curr;
        }

        // Final answer
        return next[0];
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
    // Expected Output: 3

    cout << "Test Case 1 Output: "
         << obj.longestCommonSubsequence(text1, text2) << endl;

    // ===============================
    // Test Case 2 (Same strings)
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
    // Test Case 4 (Classic case)
    // ===============================
    string t5 = "AGGTAB";
    string t6 = "GXTXAYB";
    // Expected Output: 4

    cout << "Test Case 4 Output: "
         << obj.longestCommonSubsequence(t5, t6) << endl;

    return 0;
}