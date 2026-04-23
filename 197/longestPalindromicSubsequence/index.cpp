// Leetcode Problem 516. Longest Palindromic Subsequence
/*
Idea:
Longest Palindromic Subsequence (LPS) = LCS(s, reverse(s))

Approach:
- Reverse the string
- Apply LCS using space optimized DP (1D)

Time Complexity: O(n * n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {

        // Step 1: reverse string
        string b = s;
        reverse(b.begin(), b.end());

        // Step 2: DP arrays
        vector<int> curr(s.length() + 1, 0);
        vector<int> next(s.length() + 1, 0);

        // Step 3: LCS logic
        for (int j = b.length() - 1; j >= 0; j--)
        {
            for (int i = s.length() - 1; i >= 0; i--)
            {

                // If characters match
                if (s[i] == b[j])
                {
                    curr[i] = 1 + next[i + 1];
                }
                // If not match
                else
                {
                    curr[i] = max(next[i], curr[i + 1]);
                }
            }
            // Move current row to next
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
    // Test Case 1
    // ===============================
    string s1 = "bbbab";
    // Expected Output: 4  (LPS = "bbbb")

    cout << "Test Case 1 Output: "
         << obj.longestPalindromeSubseq(s1) << endl;

    // ===============================
    // Test Case 2
    // ===============================
    string s2 = "cbbd";
    // Expected Output: 2  (LPS = "bb")

    cout << "Test Case 2 Output: "
         << obj.longestPalindromeSubseq(s2) << endl;

    // ===============================
    // Test Case 3
    // ===============================
    string s3 = "a";
    // Expected Output: 1

    cout << "Test Case 3 Output: "
         << obj.longestPalindromeSubseq(s3) << endl;

    // ===============================
    // Test Case 4
    // ===============================
    string s4 = "agbdba";
    // Expected Output: 5  (LPS = "abdba")

    cout << "Test Case 4 Output: "
         << obj.longestPalindromeSubseq(s4) << endl;

    return 0;
}