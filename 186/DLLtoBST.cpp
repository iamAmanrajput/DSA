// Convert Sorted Doubly Linked List to Binary Search Tree

#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node
{
    int data;
    Node *prev; // will act as left in BST
    Node *next; // will act as right in BST

    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

// Insert node at the end of DLL
void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    // If list is empty
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    // Attach at tail
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Print DLL (forward traversal)
void printDLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Convert sorted DLL to BST using inorder simulation
Node *sortedDLLToBST(Node *&head, int n)
{
    // Base case: no nodes left
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // Step 1: Build left subtree
    Node *leftSubtree = sortedDLLToBST(head, n - 1 - n / 2);

    // Step 2: Current node becomes root
    Node *root = head;

    // Connect left subtree
    root->prev = leftSubtree;

    // Move head forward (like inorder traversal)
    head = head->next;

    // Step 3: Build right subtree
    root->next = sortedDLLToBST(head, n / 2);

    return root;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // Sorted values (important)
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 7; i++)
    {
        insertAtTail(head, tail, arr[i]);
    }

    cout << "Doubly Linked List: ";
    printDLL(head); // Output: 1 2 3 4 5 6 7

    // Convert DLL to BST
    Node *root = sortedDLLToBST(head, 7);

    return 0;
}