// GFG Problem Transform to Sum Tree

#include <bits/stdc++.h>
using namespace std;

// Definition of Binary Tree Node
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
    // Helper function jo subtree ka total sum return karta hai
    int sumHelper(Node *node)
    {
        // Base case: agar node NULL hai to sum = 0
        if (node == NULL)
            return 0;

        // Current node ka original value store kar liya
        int oldVal = node->data;

        // Left subtree ka sum
        int leftSum = sumHelper(node->left);

        // Right subtree ka sum
        int rightSum = sumHelper(node->right);

        // Current node ko update kar rahe hain
        // (sirf left + right subtree ka sum)
        node->data = leftSum + rightSum;

        // Total sum return kar rahe hain
        // (updated value + original value)
        return node->data + oldVal;
    }

    // Ye function tree ko Sum Tree me convert karta hai
    void toSumTree(Node *node)
    {
        sumHelper(node);
    }
};

// Inorder traversal print karne ke liye (checking ke liye)
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
            Test Case Tree
                  10
                 /  \
                5    3
               / \
              2   1

        Original Inorder: 2 5 1 10 3
    */

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);

    cout << "Inorder before Sum Tree: ";
    inorder(root);
    cout << endl;

    Solution obj;
    obj.toSumTree(root);

    /*
        After Sum Tree conversion:
        Leaf nodes -> 0
        Tree becomes:

                  11
                 /  \
                3    0
               / \
              0   0

        Inorder After: 0 3 0 11 0
    */

    cout << "Inorder after Sum Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
