// Delete a Node in Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Node with data " << this->data << " deleted" << endl;
    }
};

int findLength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    Node *newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Function to delete a node
void deleteNode(int position, Node *&head, Node *&tail)
{
    // Case 0: Invalid position (like position <= 0)
    if (position <= 0)
    {
        cout << "Invalid position to delete\n";
        return;
    }

    // Case 1: If list is empty
    if (head == NULL)
    {
        cout << "Cannot delete, Linked List is Empty\n";
        return;
    }

    int len = findLength(head);

    // Case 2: Position greater than list length
    if (position > len)
    {
        cout << "Invalid position: exceeds list length\n";
        return;
    }

    // Case 3: Delete from beginning (position = 1)
    if (position == 1)
    {
        Node *temp = head; // Temporary pointer to old head
        head = head->next; // Move head to next node
        temp->next = NULL; // Disconnect old head
        delete temp;       // Free memory
        if (head == NULL)  // If list is now empty, tail ko bhi NULL karo
            tail = NULL;
        return;
    }

    // Case 4: Delete from end (position == length)
    if (position == len)
    {
        // Step 1: Traverse to (position - 1)th node
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }

        // Step 2: Disconnect last node
        Node *temp = tail;
        prev->next = NULL;

        // Step 3: Update tail
        tail = prev;

        // Step 4: Delete last node
        delete temp;
        return;
    }

    // Case 5: Delete from middle
    // Step 1: Traverse to (position - 1)th node
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }

    Node *curr = prev->next; // Node to delete

    // Step 2: Update links
    prev->next = curr->next;
    curr->next = NULL;

    // Step 3: Free memory
    delete curr;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 40);
    insertAtPosition(100, 2, head, tail);
    insertAtPosition(12, 0, head, tail);
    insertAtPosition(22, 6, head, tail);

    cout << "Original List: ";
    print(head); // 12 30 20 100 50 40 22

    deleteNode(1, head, tail);  // Delete head (12)
    deleteNode(3, head, tail);  // Delete middle node (100)
    deleteNode(5, head, tail);  // Delete tail (22)
    deleteNode(10, head, tail); // Invalid position

    cout << "Final List after deletions: ";
    print(head); // Expected: 30 20 50 40

    return 0;
}

// output
// Original List: 12 30 20 100 50 40 22
// Node with data 12 deleted
// Node with data 100 deleted
// Node with data 22 deleted
// Invalid position: exceeds list length
// Final List after deletions: 30 20 50 40