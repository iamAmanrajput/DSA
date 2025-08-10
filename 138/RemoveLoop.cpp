//  Remove Loop in Linked List -- GFG

#include <iostream>
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

// Insert at end
void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Create a loop for testing (last node points to given position)
void createLoop(Node *&head, int pos)
{
    if (!head || pos == 0)
        return;
    Node *loopNode = NULL;
    Node *temp = head;
    int count = 1;
    while (temp->next)
    {
        if (count == pos)
            loopNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopNode; // create loop
}

// Remove loop (your style logic)
Node *removeLoop(Node *&head)
{
    if (!head || !head->next)
        return head;

    Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        { // loop detected
            break;
        }
    }

    // No loop case
    if (slow != fast)
        return head;

    // Step 2: Find start of loop
    slow = head;
    Node *prev = nullptr;

    while (slow != fast)
    {
        prev = fast; // keep track of last node before meeting point
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Break the loop
    if (prev)
    {
        prev->next = nullptr;
    }
    else
    {
        // Special case: loop starts at head
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = nullptr;
    }

    return head;
}

int main()
{
    Node *head = NULL;

    // Insert nodes
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    // Create loop (last node points to node at position 2)
    createLoop(head, 2);

    // Remove loop
    head = removeLoop(head);

    // Print list after loop removal
    printList(head);

    return 0;
}
