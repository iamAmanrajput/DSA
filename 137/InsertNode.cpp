// Insertion & Deletion in Doubly Linked List
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

void print(Node *&head)
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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
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
    else
    {
        Node *newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    int len = getLength(head);

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    int i = 1;
    Node *prevNode = head;
    while (i < position - 1)
    {
        prevNode = prevNode->next;
        i++;
    }
    Node *curr = prevNode->next;
    Node *newNode = new Node(data);

    prevNode->next = newNode;
    newNode->prev = prevNode;

    curr->prev = newNode;
    newNode->next = curr;
}

void deleteFromPos(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    //  Invalid position (like position <= 0)
    if (position <= 0)
    {
        cout << "Invalid position to delete\n";
        return;
    }

    // single node
    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    // delete from start

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);

    if (position > len)
    {
        cout << "Position out of range" << endl;
        return;
    }

    // delete from end

    if (position == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    // delete from middle of linked list
    int i = 1;
    Node *left = head;
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;

    left->next = right;
    right->prev = left;

    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
    return;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(head); // 10 20 30
    cout << endl;

    insertAtHead(head, tail, 9);

    print(head); // 9 10 20 30
    cout << endl;

    insertAtTail(head, tail, 500);

    print(head); // 9 10 20 30 500
    cout << endl;

    insertAtPosition(head, tail, 3, 12);

    print(head); // 9 10 12 20 30 500
    cout << endl;

    deleteFromPos(head, tail, 1);

    print(head); // 10 12 20 30 500
    cout << endl;

    return 0;
}