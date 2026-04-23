// Leetcode Problem 72. Edit Distance
// TC O(3^(n + m))
// SC O(n + m)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function to find minimum operations
    int solve(string a, string b, int i, int j)
    {

        // Base Case 1:
        // If string 'a' is finished, we need to insert remaining characters of 'b'
        if (i == a.length())
        {
            return b.length() - j;
        }

        // Base Case 2:
        // If string 'b' is finished, we need to delete remaining characters of 'a'
        if (j == b.length())
        {
            return a.length() - i;
        }

        int ans = 0;

        // If characters match → move both pointers
        if (a[i] == b[j])
        {
            ans = solve(a, b, i + 1, j + 1);
        }
        else
        {
            // Replace operation
            int replace = 1 + solve(a, b, i + 1, j + 1);

            // Insert operation
            int insert = 1 + solve(a, b, i, j + 1);

            // Delete operation
            int remove = 1 + solve(a, b, i + 1, j);

            // Take minimum of all operations
            ans = min(insert, min(remove, replace));
        }

        return ans;
    }

    int minDistance(string word1, string word2)
    {
        return solve(word1, word2, 0, 0);
    }
};

int main()
{
    Solution obj;

    string word1 = "horse";
    string word2 = "ros";

    int result = obj.minDistance(word1, word2);

    cout << "Minimum operations required: " << result << endl;

    return 0;
}