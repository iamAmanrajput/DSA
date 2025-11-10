// Leetcode Problem 155 - Min Stack

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    vector<pair<int, int>> st;

    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            pair<int, int> p = make_pair(val, val);
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }
};

int main()
{
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Top: " << ms.top() << endl;    // 2
    cout << "Min: " << ms.getMin() << endl; // 2

    ms.pop(); // removes 2

    cout << "Top after pop: " << ms.top() << endl;    // 7
    cout << "Min after pop: " << ms.getMin() << endl; // 3

    return 0;
}
