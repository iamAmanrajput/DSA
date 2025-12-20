// Implementation of Circular Doubly Ended Queue
// If the question does not specifically mention a circular double-ended queue,
// we can simply implement a double-ended queue (deque).

#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    // Constructor
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1; // Queue empty
        rear = -1;
    }

    //  Insert element from REAR
    void pushRear(int data)
    {
        /*
        Queue FULL conditions:
        1️ front == 0 and rear == size - 1
        2️ front == rear + 1 (circular full condition)
        */
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue is Full, Cannot Insert " << data << endl;
            return;
        }

        // First insertion
        if (front == -1)
        {
            front = rear = 0;
        }
        // Circular case
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        // Normal case
        else
        {
            rear++;
        }

        arr[rear] = data;
    }

    //  Insert element from FRONT
    void pushFront(int data)
    {
        // Queue full
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue is Full, Cannot Insert " << data << endl;
            return;
        }

        // First insertion
        if (front == -1)
        {
            front = rear = 0;
        }
        // Circular case
        else if (front == 0)
        {
            front = size - 1;
        }
        // Normal case
        else
        {
            front--;
        }

        arr[front] = data;
    }

    //  Delete element from FRONT
    void popFront()
    {
        // Queue empty
        if (front == -1)
        {
            cout << "Queue is Empty, Cannot Pop" << endl;
            return;
        }

        // Single element
        if (front == rear)
        {
            front = rear = -1;
        }
        // Circular move
        else if (front == size - 1)
        {
            front = 0;
        }
        // Normal move
        else
        {
            front++;
        }
    }

    //  Delete element from REAR
    void popRear()
    {
        // Queue empty
        if (front == -1)
        {
            cout << "Queue is Empty, Cannot Pop" << endl;
            return;
        }

        // Single element
        if (front == rear)
        {
            front = rear = -1;
        }
        // Circular move
        else if (rear == 0)
        {
            rear = size - 1;
        }
        // Normal move
        else
        {
            rear--;
        }
    }

    //  Display queue elements
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        // Normal order
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        // Circular order
        else
        {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Deque dq(5);

    //  Test Case 1: Push from rear
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);
    dq.display(); // 10 20 30

    //  Test Case 2: Push from front
    dq.pushFront(5);
    dq.pushFront(2);
    dq.display(); // 2 5 10 20 30

    //  Test Case 3: Queue full
    dq.pushRear(99); // Should not insert

    //  Test Case 4: Pop from front
    dq.popFront();
    dq.display(); // 5 10 20 30

    //  Test Case 5: Pop from rear
    dq.popRear();
    dq.display(); // 5 10 20

    //  Test Case 6: Remove all elements
    dq.popFront();
    dq.popFront();
    dq.popFront();
    dq.display(); // Empty

    //  Test Case 7: Pop from empty queue
    dq.popRear(); // Cannot pop

    return 0;
}
