// Leetcode Problem 225. Implement Stack using Queues

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q; // Single queue to implement stack

    // Constructor
    MyStack()
    {
        // Nothing to initialize
    }

    // Push element x onto stack
    void push(int x)
    {
        // Step 1: Push element into queue
        q.push(x);

        // Step 2: Rotate the queue so that
        // newly added element comes to the front
        int size = q.size();
        for (int i = 0; i < size - 1; i++)
        {
            int frontElement = q.front();
            q.pop();
            q.push(frontElement);
        }
    }

    // Removes the element on top of the stack and returns it
    int pop()
    {
        int topElement = q.front(); // Front acts as stack top
        q.pop();
        return topElement;
    }

    // Get the top element
    int top()
    {
        return q.front();
    }

    // Returns true if the stack is empty
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack st;

    // Test Case
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // Expected: 30

    cout << "Pop element: " << st.pop() << endl; // Expected: 30
    cout << "Pop element: " << st.pop() << endl; // Expected: 20

    cout << "Top element: " << st.top() << endl; // Expected: 10

    cout << "Is stack empty? " << st.empty() << endl; // Expected: 0 (false)

    st.pop(); // removes 10

    cout << "Is stack empty? " << st.empty() << endl; // Expected: 1 (true)

    return 0;
}
