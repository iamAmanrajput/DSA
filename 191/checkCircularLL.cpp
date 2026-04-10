// Check Circular Linked List
#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Function using unordered_map
bool isCircular(Node *head)
{
    unordered_map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        // agar pehle se visited hai → cycle hai
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false; // NULL tak pahuch gaye → no cycle
}

int main()
{
    // Create nodes
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = head;

    // Check
    if (isCircular(head))
    {
        cout << "Linked List is Circular" << endl;
    }
    else
    {
        cout << "Linked List is NOT Circular" << endl;
    }

    return 0;
}