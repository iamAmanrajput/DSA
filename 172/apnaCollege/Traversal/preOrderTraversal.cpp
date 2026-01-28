// Leetcode Problem 144. Binary Tree Preorder Traversal

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

// Preorder traversal (for verification)
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    // Given preorder sequence
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    // Build binary tree
    Node *root = buildTree(preOrder);

    // Print preorder traversal of constructed tree
    cout << "Preorder traversal of constructed tree: ";
    preorderTraversal(root);

    return 0;
}

// Preorder traversal of constructed tree: 1 2 3 4 5