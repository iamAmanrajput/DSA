// LEETCODE 20. Valid Parentheses

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st; // stack to store opening brackets

        for (int i = 0; i < s.size(); i++)
        {

            char ch = s[i]; // current character

            // Opening bracket → push to stack
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                // Closing bracket but stack empty → invalid
                if (st.empty())
                {
                    return false;
                }

                // top stored character
                char topCh = st.top();

                // Matching pairs check
                if (ch == ')' && topCh == '(')
                {
                    st.pop();
                }
                else if (ch == '}' && topCh == '{')
                {
                    st.pop();
                }
                else if (ch == ']' && topCh == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        // End of loop → stack must be empty to be valid
        return st.empty();
    }
};

int main()
{
    Solution obj;

    string test = "{[()]}"; // sample test case

    if (obj.isValid(test))
    {
        cout << "Valid\n";
    }
    else
    {
        cout << "Invalid\n";
    }

    return 0;
}

// output

// Valid