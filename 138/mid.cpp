// Find middle of Linked List -- (LC)

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Node with data " << this->data << " deleted" << endl;
    }
};

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

Node *getMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list is Empty" << endl;
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next; // even ke case me 30 ko hi answer consider karega

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);

    cout << "Middle node is : " << getMiddle(head)->data << endl;

    return 0;
}

// output
// 10 20 30 40 50
// Middle node is : 30