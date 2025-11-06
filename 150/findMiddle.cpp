#include <iostream>
#include <stack>
using namespace std;

void findMiddle(stack<int> &st, int totalSize)
{
    // Edge case: Empty stack
    if (totalSize == 0)
    {
        cout << "Stack is empty!";
        return;
    }

    // Edge case: Only one element
    if (totalSize == 1)
    {
        cout << st.top();
        return;
    }

    // Base case: Middle reached
    if (st.size() == (totalSize / 2) + 1)
    {
        cout << st.top();
        return;
    }

    int temp = st.top();
    st.pop();

    findMiddle(st, totalSize);

    st.push(temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    int size = st.size();

    findMiddle(st, size);

    return 0;
}
