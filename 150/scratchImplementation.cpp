#include <iostream>
using namespace std;

class Stack
{

public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            // space available
            top++;
            arr[top] = data;
        }
        else
        {
            // Space Not Available
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            // empty stack
            cout << "Stack Underflow, Can't delete element" << endl;
        }
        else
        {
            // stack is non empty
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "There is not element in Stack" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    // return number of valid elements present in stack
    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // create a stack of size 10
    Stack s(10);

    // push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Current Top: " << s.getTop() << endl;                // 40
    cout << "Current Size: " << s.getSize() << endl;              // 4
    cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // No

    // pop one element
    s.pop();
    cout << "After one pop, New Top: " << s.getTop() << endl; // 30
    cout << "New Size: " << s.getSize() << endl;              // 3

    // print full stack (top -> bottom)
    cout << "Stack Elements (top -> bottom): ";
    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Final Size of stack: " << s.getSize() << endl;       // 0
    cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Yes

    return 0;
}

/*
Expected Output:

Current Top: 40
Current Size: 4
Is Empty? No
After one pop, New Top: 30
New Size: 3
Stack Elements (top -> bottom): 30 20 10
Final Size of stack: 0
Is Empty? Yes
*/