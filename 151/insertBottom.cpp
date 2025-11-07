// GFG PROBLEM - Insert an Element at the Bottom of a Stack

// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertHelper(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertHelper(st, x);

        st.push(temp);
    }

    stack<int> insertAtBottom(stack<int> st, int x)
    {
        insertHelper(st, x);
        return st;
    }
};

int main()
{
    // Test case
    // Stack: {4,3,2,1,8} (4 = bottom, 8 = top)
    // Insert x = 2 at bottom

    stack<int> st;

    // Push in order so 4 bottom, 8 top
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);

    int x = 2;

    Solution obj;
    stack<int> result = obj.insertAtBottom(st, x);

    // Print result: bottom first
    vector<int> out;
    while (!result.empty())
    {
        out.push_back(result.top());
        result.pop();
    }

    // Reverse print to show bottom first
    for (int i = out.size() - 1; i >= 0; i--)
        cout << out[i] << " ";

    return 0;
}

// 2 4 3 2 1 8
