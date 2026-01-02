// Gfg Problem - Stream First Non-Repeating
// Time: O(n)
// Space: O(1) (fixed size frequency array)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string firstNonRepeating(string &s)
    {
        // Array to store frequency of characters (a-z)
        int freq[26] = {0};

        // Queue to keep track of characters in order
        queue<char> q;

        // Final answer string
        string ans = "";

        // Traverse each character of the string
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            // Step 1: Increase frequency of current character
            freq[ch - 'a']++;

            // Step 2: Push current character into queue
            q.push(ch);

            // Step 3: Remove repeating characters from front of queue
            while (!q.empty())
            {
                // If front character is repeating, remove it
                if (freq[q.front() - 'a'] > 1)
                {
                    q.pop();
                }
                // Else front character is first non-repeating
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }

            // Step 4: If queue becomes empty, no non-repeating character
            if (q.empty())
            {
                ans.push_back('#');
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    // Test Case
    string s = "aabc";

    /*
      Explanation:
      a -> a
      a -> #
      b -> b
      c -> b

      Output: a#bb
    */

    cout << "Input string: " << s << endl;
    cout << "First Non-Repeating characters: "
         << obj.firstNonRepeating(s) << endl;

    return 0;
}

// Input string: aabc
// First Non-Repeating characters: a#bb
