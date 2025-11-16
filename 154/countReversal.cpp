// Gfg Problem Count the Reversals


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMinReversals(string s)
    {

        // If length is odd → impossible
        if (s.size() % 2 != 0)
            return -1;

        stack<char> st;

        // Build stack by removing valid "{}" pairs
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '{')
            {
                st.push('{'); // opening always pushed
            }
            else
            { // char is '}'

                // If top is '{', this is a valid pair → pop
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    // Either stack empty OR top is '}', push
                    st.push('}');
                }
            }
        }

        int reverseCount = 0;

        // Fix remaining unbalanced braces in pairs
        while (!st.empty())
        {
            char c1 = st.top();
            st.pop(); // top character
            char c2 = st.top();
            st.pop(); // next character

            // If both same '{{' or '}}' → 1 reversal
            if (c1 == c2)
            {
                reverseCount += 1;
            }
            // If different '}{' → 2 reversals
            else
            {
                reverseCount += 2;
            }
        }

        return reverseCount;
    }
};

// ------------------ MAIN + TEST CASE ------------------

int main()
{
    Solution obj;

    string s = "}{{}}{{{";
    // Expected Output: 3

    cout << obj.countMinReversals(s) << endl;

    return 0;
}
