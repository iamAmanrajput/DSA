// 25. Reverse Nodes in k-Group -- (LC)

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

int getLength(Node *&head)
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

Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty";
        return head;
    }

    int len = getLength(head);
    if (k > len)
    {
        cout << "Enter valid value of k";
        return head;
    }

    // it means number of nodes in LL is >= k
    // step - 1 - reverse first k node of linked list
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 2 - recursive Call
    if (forward != NULL)
    {
        // we still have nodes left to reverse
        head->next = reverseKNodes(forward, k);
    }

    // return head of the modified LL
    return prev;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(head);

    head = reverseKNodes(head, 3);
    print(head);

    return 0;
}

// output
// 10 20 30 40 50 60
// 30 20 10 60 50 40
