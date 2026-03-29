// Convert BST Into Doubly Linked List

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void convertIntoSortedDLL(Node *root, Node *&head)
{
    // Base case: if tree is empty, return
    if (root == NULL)
    {
        return;
    }

    // Step 1: Convert right subtree first
    // (we are doing reverse inorder: Right → Root → Left)
    convertIntoSortedDLL(root->right, head);

    // Step 2: Attach current root node to DLL

    // Make current node's next point to current head
    root->right = head;

    // If head is not NULL, link its prev to current node
    if (head != NULL)
    {
        head->left = root; // connect back pointer
    }

    // Step 3: Move head to current node
    // (current node becomes new head of DLL)
    head = root;

    // Step 4: Convert left subtree
    convertIntoSortedDLL(root->left, head);
}

// Insert into BST
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder print (sorted output check karne ke liye)
void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to print Linked List
void printDLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main()
{
    Node *root = NULL;

    // BST bana rahe hain
    int arr[] = {4, 2, 5, 1, 3};

    for (int i = 0; i < 5; i++)
    {
        root = insert(root, arr[i]);
    }

    cout << "Inorder (Sorted): ";
    inorder(root); // Output: 1 2 3 4 5
    cout << endl;

    Node *head = NULL;
    convertIntoSortedDLL(root, head);

    cout << "Doubly Sorted Linked List: ";
    printDLL(head);

    return 0;
}

// Inorder (Sorted): 1 2 3 4 5
// Doubly Sorted Linked List: 1 2 3 4 5