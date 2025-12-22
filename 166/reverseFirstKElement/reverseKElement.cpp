// Gfg Problem - Reverse k elements of queue
// Tc - 0(N)
// Sc - 0(N)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    // Function to reverse first k elements of a queue
    queue<int> reverseFirstK(queue<int> q, int k)
    {

        // Edge case: if k is invalid
        if (k <= 0 || k > q.size())
            return q;

        stack<int> st;
        int remainingElem = q.size() - k;

        // Step 1: Push first k elements of queue into stack
        for (int i = 0; i < k; i++)
        {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Pop elements from stack and push back to queue
        // This reverses the first k elements
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move remaining elements to the back to maintain order
        while (remainingElem--)
        {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

int main()
{
    queue<int> q;

    // Test Case
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    Solution obj;
    queue<int> result = obj.reverseFirstK(q, k);

    // Print the result
    cout << "Queue after reversing first " << k << " elements: ";
    while (!result.empty())
    {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}

// Input
// Queue = 1 2 3 4 5
// k = 3

// Output
// Queue after reversing first 3 elements: 3 2 1 4 5
