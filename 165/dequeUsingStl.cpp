#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // Create a deque of integers
    deque<int> dq;

    // Test Case 1: Insert elements from rear
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "After push_back operations: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Test Case 2: Insert elements from front
    dq.push_front(5);
    dq.push_front(1);

    cout << "After push_front operations: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Test Case 3: Remove element from front
    dq.pop_front();

    cout << "After pop_front: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Test Case 4: Remove element from rear
    dq.pop_back();

    cout << "After pop_back: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Test Case 5: Access front and rear elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Rear element: " << dq.back() << endl;

    // Test Case 6: Check size and empty condition
    cout << "Current size of deque: " << dq.size() << endl;

    if (dq.empty())
        cout << "Deque is empty" << endl;
    else
        cout << "Deque is not empty" << endl;

    // Test Case 7: Clear the deque
    dq.clear();

    cout << "After clear operation, size: " << dq.size() << endl;

    return 0;
}

// After push_back operations: 10 20 30
// After push_front operations: 1 5 10 20 30
// After pop_front: 5 10 20 30
// After pop_back: 5 10 20
// Front element: 5
// Rear element: 20
// Current size of deque: 3
// Deque is not empty
// After clear operation, size: 0
