// Insert a Node in Linked List

#include <iostream>
using namespace std;

// Node class definition
class Node
{
public:
    int data;   // Node ke andar data store hoga
    Node *next; // Pointer jo next node ka address store karega

    // Default Constructor
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterized Constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

// Function to find length of linked list
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

// Function to insert a node right at the end of the linked list
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Create a node
    Node *newNode = new Node(data);

    // Step 2: Connect with tail node
    tail->next = newNode;

    // Step 3: Update tail pointer
    tail = newNode;
}

// Function to insert a new node at the beginning (head) of the linked list
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Naya node banao jisme data hoga
    Node *newNode = new Node(data);

    // Step 2: Naye node ka next pointer current head ko point karega
    newNode->next = head;

    // Step 3:
    // Head ko update karke naye node pe le aao (naya node ab head ban gaya)
    head = newNode;
}

// Insert at Specific Position
void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step - 1 : Find that Position : prev & current

    // insert at head if position is 0
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // insert at tail if position is last
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

    // step - 2 : Create a Node
    Node *newNode = new Node(data);

    // step - 3
    newNode->next = curr;

    // step -4
    prev->next = newNode;
}

// Function to print the linked list
void print(Node *head)
{
    Node *temp = head; // Temporary pointer banaya traverse karne ke liye

    // Jab tak temp NULL nahi ho jata, tab tak data print karte jao
    while (temp != NULL)
    {
        cout << temp->data << " "; // Current node ka data print karo
        temp = temp->next;         // Next node pe move karo
    }

    cout << endl; // Line break after printing the list
}

int main()
{
    // Initial linked list
    Node *head = NULL;
    Node *tail = NULL;

    // Insert new nodes at the head
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    // Insert new nodes at the tail
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 40);

    // Insert new node at Specific position
    insertAtPosition(100, 2, head, tail);
    insertAtPosition(12, 0, head, tail);
    insertAtPosition(22, 6, head, tail);

    // Final list: 12 -> 30 -> 20 -> 100 -> 50 -> 40 -> 22
    print(head);

    return 0;
}
