// GFG Problem Transform to sum tree

#include <iostream>
using namespace std;

/* Binary Tree Node */
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

class Solution
{
public:
    // Recursive function to convert tree to Sum Tree
    int solve(Node *node)
    {
        // Base case
        if (node == NULL)
        {
            return 0;
        }

        // Recursively get sum of left and right subtree
        int leftSum = solve(node->left);
        int rightSum = solve(node->right);

        // Store current node value
        int currVal = node->data;

        // Update node with sum of left + right subtree
        node->data = leftSum + rightSum;

        // Return total sum of subtree (original value + left + right)
        return node->data + currVal;
    }

    void toSumTree(Node *node)
    {
        solve(node);
    }
};

/* Helper function to print tree in inorder */
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    /*
        Test Case:

              10
             /  \
           20    30

        After Sum Tree:

              50
             /  \
            0    0
    */

    // Creating tree manually
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    Solution obj;

    cout << "Original Tree (Inorder): ";
    inorder(root);
    cout << endl;

    // Convert to Sum Tree
    obj.toSumTree(root);

    cout << "Sum Tree (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}