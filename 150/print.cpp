#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // create a stack of integers
    stack<int> st;

    // push elements into the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40); // top = 40

    // print the stack (from top to bottom)
    cout << "Stack elements (top -> bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " "; // print the top element
        st.pop();                // remove the top element
    }
    cout << endl;

    return 0;
}

// Output: Stack elements (top -> bottom): 40 30 20 10
