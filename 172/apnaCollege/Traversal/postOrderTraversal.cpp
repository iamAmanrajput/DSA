// Leetcode Problem 145. Binary Tree Postorder Traversal

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Static index to track preorder traversal
static int idx = -1;

/*
    Build Binary Tree using Preorder traversal
    Rule: Root -> Left -> Right
    -1 represents NULL
*/
Node *buildTree(vector<int> &preOrder)
{
    idx++;

    if (preOrder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);  // LEFT
    root->right = buildTree(preOrder); // RIGHT

    return root;
}

/*
    Postorder Traversal
    Rule: Left -> Right -> Root
*/
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);  // Left
    postorderTraversal(root->right); // Right
    cout << root->data << " ";       // Root
}

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    // Build tree
    Node *root = buildTree(preOrder);

    // Postorder traversal output
    cout << "Postorder traversal of constructed tree: ";
    postorderTraversal(root);

    return 0;
}

// Postorder traversal of constructed tree : 2 4 5 3 1
