// Leetcode Problem 94. Binary Tree Inorder Traversal
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize node
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Static index to track current position in preorder array
static int idx = -1;

/*
    Function: buildTree
    Logic:
    - Preorder traversal is followed: Root -> Left -> Right
    - -1 represents NULL node
*/
Node *buildTree(vector<int> &preOrder)
{
    idx++;

    // Base case: if value is -1, no node exists
    if (preOrder[idx] == -1)
    {
        return NULL;
    }

    // Create current node
    Node *root = new Node(preOrder[idx]);

    // Recursively build left subtree
    root->left = buildTree(preOrder);

    // Recursively build right subtree
    root->right = buildTree(preOrder);

    return root;
}

// inorder traversal (for verification)
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Given preorder sequence
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    // Build binary tree
    Node *root = buildTree(preOrder);

    // Print inorder traversal of constructed tree
    cout << "inorder traversal of constructed tree: ";
    inorderTraversal(root);

    return 0;
}

// inorder traversal of constructed tree: 2 1 4 3 5