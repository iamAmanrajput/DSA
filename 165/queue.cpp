#include <iostream> // For input-output
#include <queue>    // For using queue STL
using namespace std;

int main()
{
    // Creation of queue
    queue<int> q;

    // Insertion of elements into the queue (FIFO order)
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    // Print size of the queue
    cout << "Size of Queue is " << q.size() << endl;

    // Removal of front element from the queue
    q.pop();

    // Check whether the queue is empty or not
    if (q.empty())
    {
        cout << "Q is empty" << endl;
    }
    else
    {
        cout << "Q is not empty." << endl;
    }

    // Access and print the front element of the queue
    cout << "Front Element is " << q.front() << endl;

    return 0; // End of program
}

// Output

// Size of Queue is 5
// Q is not empty.
// Front Element is 10