#include <iostream>
using namespace std;

class CirQueue
{
public:
    int size;  // Total capacity of queue
    int *arr;  // Dynamic array to store elements
    int front; // Points to first element
    int rear;  // Points to last element

    // Constructor
    CirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1; // -1 means queue is empty
        rear = -1;
    }

    // PUSH operation
    void push(int data)
    {
        /*
        Queue FULL conditions:
        1 front == 0 and rear == size - 1
        2 front == rear + 1  (circular full condition)
        */
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue is Full, Cannot Insert " << data << endl;
            return;
        }

        // If queue is empty (first element insertion)
        if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        // Circular case: rear reached end but space exists at beginning
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        // Normal case
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    // POP operation
    void pop()
    {
        // Queue empty
        if (front == -1)
        {
            cout << "Queue is Empty, Cannot Pop" << endl;
            return;
        }

        // Single element present
        if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // Circular movement of front
        else if (front == size - 1)
        {
            front = 0;
        }
        // Normal case
        else
        {
            front++;
        }
    }

    // Display Queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        // If rear >= front → normal order
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        // If rear < front → circular order
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    CirQueue q(5);

    // Test Case 1: Insert elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display(); // 10 20 30 40

    // Test Case 2: Delete two elements
    q.pop();
    q.pop();
    q.display(); // 30 40

    // Test Case 3: Circular insertion
    q.push(50);
    q.push(60);
    q.display(); // 30 40 50 60

    //  Test Case 4: Queue full
    q.push(70); // Should show "Queue is Full"

    //  Test Case 5: Remove all elements
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display(); // Queue is Empty

    // Test Case 6: Pop from empty queue
    q.pop(); // Cannot pop

    return 0;
}
