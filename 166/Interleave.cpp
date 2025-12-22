// Gfg Problem - Interleave the First Half of the Queue with Second Half
// Tc - 0(N)
// Sc - 0(N)

#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    void rearrangeQueue(queue<int> &q)
    {

        // Agar queue empty ho to kuch karne ki zarurat nahi
        if (q.empty())
        {
            return;
        }

        int n = q.size(); // Total elements in queue
        int k = n / 2;    // First half ka size
        int count = 0;

        queue<int> q2; // First half store karne ke liye extra queue

        // Step 1: First half elements ko q2 me daalo
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            q2.push(temp);
            count++;

            if (count == k)
            {
                break;
            }
        }

        // Step 2: Interleaving start karo
        // Ek element q2 se, phir ek element q se
        while (!q.empty() && !q2.empty())
        {
            int first = q2.front();
            q2.pop();
            q.push(first);

            int second = q.front();
            q.pop();
            q.push(second);
        }

        // Step 3: Agar elements odd hain to last element ko back me push karo
        if (n & 1)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }
    }
};

int main()
{
    queue<int> q;

    // Test Case
    // Queue: 1 2 3 4
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    Solution obj;
    obj.rearrangeQueue(q);

    // Output print karo
    cout << "Interleaved Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

// Queue = 1 2 3 4
// First half = 1 2
// Second half = 3 4
// Interleaved Queue: 1 3 2 4
