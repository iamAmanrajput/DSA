// Leetcode Problem 222. Count Complete Tree Nodes
// TC - O(n)
// postorder traversal

#include <bits/stdc++.h>
using namespace std;

/*
    Definition of a Binary Tree Node
*/
struct TreeNode
{
    int val;         // Value stored in the node
    TreeNode *left;  // Pointer to left child
    TreeNode *right; // Pointer to right child

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value, left child and right child
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to count total number of nodes in a binary tree
    int countNodes(TreeNode *root)
    {

        // Base case:
        // Agar tree empty hai, to nodes = 0
        if (root == NULL)
        {
            return 0;
        }

        // Left subtree ke nodes count karo
        int leftNode = countNodes(root->left);

        // Right subtree ke nodes count karo
        int rightNode = countNodes(root->right);

        // Current node ko 1 count karke
        // left + right subtree ke nodes add karo
        return leftNode + rightNode + 1;
    }
};

int main()
{
    /*
        Test Case Tree:
                1
               / \
              2   3
             / \
            4   5

        Expected Output:
        Total Nodes = 5
    */

    // Manually binary tree create kar rahe hain
    TreeNode *root = new TreeNode(1);    // Root node
    root->left = new TreeNode(2);        // Left child of root
    root->right = new TreeNode(3);       // Right child of root
    root->left->left = new TreeNode(4);  // Left child of node 2
    root->left->right = new TreeNode(5); // Right child of node 2

    // Solution class ka object
    Solution sol;

    // countNodes function call
    int result = sol.countNodes(root);

    // Result print karo
    cout << "Total number of nodes in the binary tree: " << result << endl;

    return 0;
}
