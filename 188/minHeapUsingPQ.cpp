// Implementation of min heap using Priority Queue

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Creates a Min Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "Top Element : " << pq.top() << endl; // Top Element : 3

    pq.pop();
    cout << "Top Element : " << pq.top() << endl; // Top Element : 4

    pq.pop();
    cout << "Top Element : " << pq.top() << endl; // Top Element : 6

    pq.pop();
    cout << "Top Element : " << pq.top() << endl; // Top Element : 8

    pq.pop();
    cout << "Top Element : " << pq.top() << endl; // Top Element : 9

    pq.pop();
    cout << "Size is : " << pq.size() << endl; // Size is : 0

    if (pq.empty())
    {
        cout << "Max Heap is Empty" << endl;
    }
    else
    {
        cout << "Max Heap is not Empty" << endl;
    }

    // output
    // Max Heap is Empty

    return 0;
}