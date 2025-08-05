// Singly Linkedlist Eample

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
    // Nodes banaye (linked list ke elements)
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    // Nodes ko link kiya (list ko chain banaya)
    first->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next is already NULL (by default from constructor)

    // List ko print kar rahe hain
    cout << "Printing Linked List" << endl;
    print(first); // head node pass kiya

    return 0;
}

// output
// Printing Linked List
// 10 20 30 40
