// Implementation of Binary Search Tree (BST)

#include <iostream>
#include <queue>
using namespace std;

// Node class representing each node of BST
class Node
{
public:
    int data;    // value stored in node
    Node *left;  // pointer to left child
    Node *right; // pointer to right child

    // Constructor to initialize node with given data
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert a node into BST
Node *insertIntoBST(Node *root, int data)
{
    // Base case: if root is NULL, create a new node
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // If data is smaller than root, insert into left subtree
    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // If data is greater or equal, insert into right subtree
        root->right = insertIntoBST(root->right, data);
    }

    return root; // return updated root
}

// Function to take input and build BST
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    // Continue inserting until user enters -1
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Function to print tree in Level Order (Breadth First Traversal)
void levelOrderPrint(Node *root)
{
    // If tree is empty, return
    if (root == NULL)
        return;

    queue<Node *> q;

    // Step 1: Push root node into queue
    q.push(root);

    // Step 2: Push NULL as level separator
    q.push(NULL);

    // Step 3: Traverse until queue becomes empty
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // If NULL encountered, it means end of current level
        if (curr == NULL)
        {
            cout << endl; // move to next line for next level

            // If queue still has nodes, add another NULL marker
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // Print current node data
            cout << curr->data << " ";

            // Push left child if exists
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            // Push right child if exists
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data for nodes (-1 to stop):" << endl;

    // Build BST from user input
    takeInput(root);

    cout << "Level Order Traversal of BST:" << endl;

    // Print BST level by level
    levelOrderPrint(root);

    return 0;
}

/*
Example Input:
10 20 5 11 17 2 4 8 6 25 15 -1

Output:
10
5 20
2 8 11 25
4 6 17
15
*/