// Leetcode Problem 232. Implement Queue using Stacks

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    // Two stacks:
    // s1 -> used for push operation
    // s2 -> used for pop / peek operation
    stack<int> s1, s2;

    // Constructor
    MyQueue()
    {
        // nothing to initialize
    }

    // Push element x to the back of queue
    void push(int x)
    {
        // Always push into s1
        s1.push(x);
    }

    // Removes the element from the front of queue and returns it
    int pop()
    {
        int pop = -1;

        // If s2 already has elements, top of s2 is front of queue
        if (!s2.empty())
        {
            pop = s2.top();
        }
        else
        {
            // Transfer all elements from s1 to s2
            // This reverses order and makes queue behavior
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
        }

        // Remove the front element
        s2.pop();
        return pop;
    }

    // Get the front element without removing it
    int peek()
    {
        int front = -1;

        // If s2 has elements, top is front
        if (!s2.empty())
        {
            front = s2.top();
        }
        else
        {
            // Move elements from s1 to s2 if s2 is empty
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }

        return front;
    }

    // Returns true if queue is empty
    bool empty()
    {
        // Queue is empty only if both stacks are empty
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue q;

    // Test case
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // Expected: 10
    cout << "Pop element: " << q.pop() << endl;    // Expected: 10
    cout << "Front element: " << q.peek() << endl; // Expected: 20

    q.push(40);

    cout << "Pop element: " << q.pop() << endl;      // Expected: 20
    cout << "Pop element: " << q.pop() << endl;      // Expected: 30
    cout << "Is queue empty? " << q.empty() << endl; // Expected: 0 (false)

    cout << "Pop element: " << q.pop() << endl;      // Expected: 40
    cout << "Is queue empty? " << q.empty() << endl; // Expected: 1 (true)

    return 0;
}
