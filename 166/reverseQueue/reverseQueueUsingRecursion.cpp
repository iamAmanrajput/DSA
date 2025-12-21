// Time Complexity 0(N)
// Space Complexity 0(1)

#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        if (q.empty())
        {
            return;
        }

        int temp = q.front();
        q.pop();

        reverseQueue(q);
        q.push(temp);
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

// Original Queue: 10 20 30 40
// Reversed Queue: 40 30 20 10