// Leetcode Problem 394. Decode String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string &s)
    {
        stack<string> st;

        // Traverse each character of string
        for (auto ch : s)
        {

            // When closing bracket found, start decoding
            if (ch == ']')
            {

                // Step 1: Extract string inside [ ]
                string stringToRepeat = "";
                while (!st.empty() && st.top() != "[")
                {
                    stringToRepeat += st.top();
                    st.pop();
                }

                // Remove '[' from stack
                st.pop();

                // Step 2: Extract number (k)
                string numericTimes = "";
                while (!st.empty() && isdigit(st.top()[0]))
                {
                    numericTimes += st.top();
                    st.pop();
                }

                // Digits were collected in reverse order
                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);

                // Step 3: Repeat decoded string n times
                string currentDecode = "";
                while (n--)
                {
                    currentDecode += stringToRepeat;
                }

                // Push decoded result back to stack
                st.push(currentDecode);
            }
            else
            {
                // Push characters, digits and '[' as string
                string temp(1, ch);
                st.push(temp);
            }
        }

        // Build final answer from stack
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;

    // Test Case
    string s = "3[a2[c]]";

    // Expected Output: accaccacc
    cout << "Decoded String: " << sol.decodeString(s) << endl;

    return 0;
}
