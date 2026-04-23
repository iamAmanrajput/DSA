// Leetcode Problem 72. Edit Distance
// Time Complexity: O(n * m)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Edit Distance (Levenshtein Distance)

    Goal:
    Convert string `a` → `b` using minimum operations.

    Allowed Operations:
    1. Insert a character
    2. Delete a character
    3. Replace a character

    Key Idea (DP Thinking):
    Let dp[i][j] = minimum operations required to convert
                   a[i...end] → b[j...end]

    Transition:
    If a[i] == b[j]:
        No operation needed → move diagonally
        dp[i][j] = dp[i+1][j+1]

    Else:
        We try all 3 operations:
        1. Insert  → dp[i][j+1]
        2. Delete  → dp[i+1][j]
        3. Replace → dp[i+1][j+1]

        dp[i][j] = 1 + min(insert, delete, replace)

    Optimization:
    Instead of full 2D DP → use 2 rows (curr + next)

*/

class Solution
{
public:
    int minDistance(string &a, string &b)
    {

        // next → dp[i][j+1] (next column)
        // curr → dp[i][j]   (current column)
        vector<int> next(a.length() + 1, 0);
        vector<int> curr(a.length() + 1, 0);

        /*
            Base Case:
            Jab b completely process ho jaye (j = b.length()),
            to a ke remaining characters delete karne padenge

            dp[i][m] = a.length() - i
        */
        for (int row = 0; row <= a.length(); row++)
        {
            next[row] = a.length() - row;
        }

        /*
            b ko right se left traverse karte hain
            kyunki dp[i][j] depend karta hai dp[i][j+1] par
        */
        for (int j = b.length() - 1; j >= 0; j--)
        {

            /*
                Jab a exhaust ho jaye (i = a.length()),
                to b ke remaining characters insert karne padenge

                dp[n][j] = b.length() - j
                Har New Column ke last cell me ans insert kro (MOST Important)
            */
            curr[a.length()] = b.length() - j;

            for (int i = a.length() - 1; i >= 0; i--)
            {

                if (a[i] == b[j])
                {
                    // Characters match → no operation needed
                    curr[i] = next[i + 1];
                }
                else
                {
                    // 3 operations try karte hain

                    int replace = 1 + next[i + 1]; // replace a[i] → b[j]
                    int insert = 1 + next[i];      // insert b[j]
                    int remove = 1 + curr[i + 1];  // delete a[i]

                    // minimum cost choose karo
                    curr[i] = min(insert, min(remove, replace));
                }
            }

            // current column ko next bana do
            next = curr;
        }

        // final answer
        return next[0];
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    string word1 = "horse";
    string word2 = "ros";

    cout << "Edit Distance: " << obj.minDistance(word1, word2) << endl;
    /*
        Expected Output: 3

        Steps:
        horse → rorse (replace h → r)
        rorse → rose  (delete r)
        rose  → ros   (delete e)
    */

    // Test Case 2
    string a = "intention";
    string b = "execution";

    cout << "Edit Distance: " << obj.minDistance(a, b) << endl;
    // Expected Output: 5

    return 0;
}