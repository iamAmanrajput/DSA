// GFG : Reverse Using Stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverse(string S)
    {
        stack<char> st;

        // Push all characters into the stack
        for (int i = 0; i < S.size(); i++)
        {
            st.push(S[i]);
        }

        // Pop and replace characters in string
        for (int i = 0; i < S.size(); i++)
        {
            S[i] = st.top();
            st.pop();
        }

        return S;
    }
};

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution obj;
    string ans = obj.reverse(s);

    cout << "Reversed string: " << ans << endl;

    return 0;
}
