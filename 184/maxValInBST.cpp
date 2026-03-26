// Maximum Value In Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

/*
Structure of a Binary Tree Node
*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    // Function to find maximum value in BST
    int maxValue(Node *root)
    {

        // In BST, maximum value is always at the rightmost node

        while (true)
        {
            // If there is no right child, current node is maximum
            if (root->right == NULL)
            {
                return root->data;
            }
            else
            {
                // Move towards right subtree
                root = root->right;
            }
        }
    }
};

int main()
{
    /*
        Test Case:
                10
               /  \
              5    20
             / \     \
            2   8     30

        Maximum value = 30
    */

    // Creating BST manually
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->right = new Node(30);

    Solution obj;

    // Function call
    int ans = obj.maxValue(root);

    cout << "Maximum value in BST is: " << ans << endl;

    return 0;
}