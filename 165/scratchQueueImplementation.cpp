#include <iostream>
using namespace std;

// Queue implementation using array
class Queue
{
public:
    int *arr;  // Dynamic array to store queue elements
    int size;  // Maximum size of queue
    int front; // Points to the front element
    int rear;  // Points to the next insertion position

    // Constructor to initialize queue
    Queue(int size)
    {
        this->size = size;
        arr = new int[size]; // Allocate memory
        front = 0;
        rear = 0;
    }

    // Function to insert an element into the queue
    void push(int data)
    {
        // Check if queue is full
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = data; // Insert element at rear
            rear++;           // Move rear forward
        }
    }

    // Function to remove an element from the queue
    void pop()
    {
        // Check if queue is empty
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            arr[front] = -1; // Optional: mark removed element
            front++;         // Move front forward

            // Reset queue when it becomes empty
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    // Function to get the front element of the queue
    int getFront()
    {
        // If queue is empty
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front]; // Return front element
        }
    }

    // Function to check whether the queue is empty
    bool isEmpty()
    {
        return (front == rear);
    }

    // Function to get current size of the queue
    int getSize()
    {
        return rear - front;
    }
};

int main()
{
    // Create a queue of size 10
    Queue q(10);

    // Insert elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // Display front element
    cout << "Front element: " << q.getFront() << endl;

    // Display current size of queue
    cout << "Queue size: " << q.getSize() << endl;

    // Remove two elements from the queue
    q.pop();
    q.pop();

    // Display front element after pop operations
    cout << "Front element after pop: " << q.getFront() << endl;

    // Check if queue is empty
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    // Display final size of queue
    cout << "Final Queue size: " << q.getSize() << endl;

    return 0;
}

// Output

// Front element: 10
// Queue size: 4
// Front element after pop: 30
// Queue is not empty
// Final Queue size: 2