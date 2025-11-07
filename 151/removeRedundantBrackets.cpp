// GFG Problem - Expression contains redundant bracket or not

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkRedundancy(string &s)
    {

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            // Push operators and '('
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {

                bool op = false; // To check if at least one operator is inside

                // Pop until '('
                while (!st.empty() && st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        op = true; // We found operator inside
                    }
                    st.pop();
                }

                // If no operator found → redundant bracket
                if (op == false)
                    return true;

                // pop '('
                if (!st.empty())
                    st.pop();
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;

    // Test case
    string expression = "((a+b))"; // Redundant brackets present

    if (obj.checkRedundancy(expression))
    {
        cout << "Redundant brackets found!" << endl;
    }
    else
    {
        cout << "No redundant brackets." << endl;
    }

    return 0;
}

// Redundant brackets found!
