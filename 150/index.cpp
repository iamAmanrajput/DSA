#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Creation
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // remove
    st.pop(); // remove 50

    cout << "Element on Top is: " << st.top() << endl; // Element on Top is: 40

    // check size
    cout << "Size of stack is: " << st.size() << endl; // Size of stack is: 4

    if (st.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl; // Stack is Not Empty
    }

    return 0;
}