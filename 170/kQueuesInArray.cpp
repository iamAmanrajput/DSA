// K Queues In An Array
#include <iostream>
using namespace std;

class KQueue
{
    int n, k, freespot;
    int *arr, *front, *rear, *next;

public:
    // Constructor
    KQueue(int _n, int _k) : n(_n), k(_k), freespot(0)
    {
        // Array to store actual values
        arr = new int[n];

        // Next array (used for free list + queue linking)
        next = new int[n];

        // Front and rear for each queue
        front = new int[k];
        rear = new int[k];

        // Initially all queues are empty
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        // Initialize free list
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // End of free list
    }

    // Push element x into queue number qi
    bool push(int x, int qi)
    {
        // Overflow check
        if (freespot == -1)
        {
            return false;
        }

        // Get free index
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // First element in this queue
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // Link new element to previous rear
            next[rear[qi]] = index;
        }

        // Mark end of queue
        next[index] = -1;

        // Update rear
        rear[qi] = index;

        // Store value
        arr[index] = x;

        return true;
    }

    // Pop element from queue number qi
    int pop(int qi)
    {
        // Underflow check
        if (front[qi] == -1)
        {
            return -1;
        }

        // Index to pop
        int index = front[qi];

        // Move front to next element
        front[qi] = next[index];

        // Add removed index back to free list
        next[index] = freespot;
        freespot = index;

        // Return popped value
        return arr[index];
    }

    // Destructor
    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{
    // Create 3 queues in an array of size 10
    KQueue q(10, 3);

    // Push elements into different queues
    q.push(10, 0);
    q.push(20, 0);
    q.push(30, 1);
    q.push(40, 2);
    q.push(50, 1);

    // Pop elements
    cout << "Pop from Queue 0: " << q.pop(0) << endl; // 10
    cout << "Pop from Queue 1: " << q.pop(1) << endl; // 30
    cout << "Pop from Queue 2: " << q.pop(2) << endl; // 40
    cout << "Pop from Queue 0: " << q.pop(0) << endl; // 20
    cout << "Pop from Queue 1: " << q.pop(1) << endl; // 50

    return 0;
}
