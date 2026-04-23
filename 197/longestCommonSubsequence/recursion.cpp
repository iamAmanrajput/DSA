// Leetcode Problem 1143. Longest Common Subsequence
/*
Time Complexity (TC): O(2^(n+m))
-> Har step pe 2 recursive calls ho rahi hain (exponential growth)

Space Complexity (SC): O(n + m)
-> Recursive call stack ki wajah se
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function to find LCS
    int solve(string &text1, string &text2, int i, int j)
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

        int ans = 0;

        // Case 1: Characters match
        if (text1[i] == text2[j])
        {
            // Include character in LCS and move both pointers
            ans = 1 + solve(text1, text2, i + 1, j + 1);
        }
        else
        {
            // Case 2: Characters do not match
            // Try skipping one character at a time and take max
            ans = max(
                solve(text1, text2, i, j + 1), // skip character from text2
                solve(text1, text2, i + 1, j)  // skip character from text1
            );
        }

        return ans;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        // Start comparing from index 0 of both strings
        return solve(text1, text2, 0, 0);
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

    // Output result
    cout << "LCS Length: " << result << endl;

    return 0;
}