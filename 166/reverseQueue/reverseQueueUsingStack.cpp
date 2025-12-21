// Time Complexity O(N)
// Space Complexity O(N)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        stack<int> st;

        // Step 1: Queue → Stack
        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Stack → Queue
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
    }
};

int main()
{
    queue<int> q;

    // 🔹 Test Case
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Original Queue: ";
    queue<int> temp = q; // copy for printing
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    Solution obj;
    obj.reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

// Input
// 10 20 30 40

// Output
// 40 30 20 10
