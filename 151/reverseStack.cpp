// GFG PROBLEM - Reverse a Stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertAtBottom(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

    void reverseStack(stack<int> &st)
    {
        if (st.empty())
            return;

        int target = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, target);
    }
};

int main()
{
    // Test Case:
    // Stack: {4, 3, 2, 1} (4 bottom, 1 top)
    // After reverse → {1, 2, 3, 4}

    stack<int> st;

    // Insert items (bottom = first)
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    Solution obj;
    obj.reverseStack(st);

    // Print reversed stack from bottom → top
    vector<int> out;
    while (!st.empty())
    {
        out.push_back(st.top());
        st.pop();
    }

    for (int i = out.size() - 1; i >= 0; i--)
        cout << out[i] << " ";

    return 0;
}
