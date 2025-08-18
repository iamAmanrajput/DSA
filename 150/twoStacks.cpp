// GFG : Two Stacks in an Array
// Approach 2

#include <iostream>
using namespace std;

class twoStacks
{
public:
    int *arr;
    int size;
    int top1, top2;

    // Constructor
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // Function to push an integer into stack1.
    void push1(int x)
    {
        if (top1 + 1 < top2)
        {
            arr[++top1] = x;
        }
        // else ignore
    }

    // Function to push an integer into stack2.
    void push2(int x)
    {
        if (top1 + 1 < top2)
        {
            arr[--top2] = x;
        }
        // else ignore
    }

    // Function to remove an element from top of stack1.
    int pop1()
    {
        if (top1 >= 0)
        {
            return arr[top1--];
        }
        else
        {
            return -1; // underflow condition
        }
    }

    // Function to remove an element from top of stack2.
    int pop2()
    {
        if (top2 < size)
        {
            return arr[top2++];
        }
        else
        {
            return -1; // underflow condition
        }
    }
};

// Driver code for testing locally
int main()
{
    twoStacks ts(10);

    // Push elements in stack1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // Push elements in stack2
    ts.push2(100);
    ts.push2(200);
    ts.push2(300);

    // Pop elements
    cout << "Pop from stack1: " << ts.pop1() << endl; // 15
    cout << "Pop from stack1: " << ts.pop1() << endl; // 10
    cout << "Pop from stack2: " << ts.pop2() << endl; // 300
    cout << "Pop from stack2: " << ts.pop2() << endl; // 200

    // More pops to test underflow
    cout << "Pop from stack1: " << ts.pop1() << endl;             // 5
    cout << "Pop from stack1 (underflow): " << ts.pop1() << endl; // -1

    return 0;
}

/*
Expected Output:
Pop from stack1: 15
Pop from stack1: 10
Pop from stack2: 300
Pop from stack2: 200
Pop from stack1: 5
Pop from stack1 (underflow): -1
*/
