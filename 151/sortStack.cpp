#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void insertSorted(stack<int> &st, int target)
    {
        // Empty stack → push
        if (st.empty())
        {
            st.push(target);
            return;
        }

        // base case
        if (st.top() >= target)
        {
            st.push(target);
            return;
        }

        // Otherwise pop and recurse
        int topElement = st.top();
        st.pop();

        insertSorted(st, target);

        // Backtrack: push old element
        st.push(topElement);
    }

    void sortStack(stack<int> &st)
    {
        if (st.empty())
            return;

        int topElem = st.top();
        st.pop();

        sortStack(st);

        insertSorted(st, topElem);
    }
};

int main()
{
    stack<int> st;

    // Test case: push 6,5,4,3,2,1
    st.push(6);
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    Solution obj;
    obj.sortStack(st);

    // Print sorted stack (top to bottom)
    cout << "Sorted Stack (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}

// Sorted Stack (top to bottom): 1 2 3 4 5 6
