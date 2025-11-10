// Leetcode Problem 32. Longest Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string &s)
    {

        if (s.length() == 0)
        {
            return 0;
        }

        int maxi = 0;

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxi = max(maxi, i - st.top());
                }
            }
        }

        return maxi;
    }
};

int main()
{
    Solution sol;

    // Test case
    string s = "(()())";
    // Longest valid parentheses = 6

    cout << "Input: " << s << endl;
    cout << "Longest Valid Parentheses Length: " << sol.longestValidParentheses(s) << endl;

    return 0;
}
