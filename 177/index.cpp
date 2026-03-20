// Leetcode Problem 110. Balanced Binary Tree
// Optimized Solution
// TC -> O(n)

#include <iostream>
#include <cmath>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    bool isBalance = true;

    // Function to calculate height and check balance
    int height(TreeNode *root)
    {
        // Base case: empty node
        if (root == NULL)
        {
            return 0;
        }

        // Get left subtree height
        int leftHeight = height(root->left);

        // Get right subtree height
        int rightHeight = height(root->right);

        // Check if current node is balanced
        // Condition: difference should not be greater than 1
        if (isBalance && abs(leftHeight - rightHeight) > 1)
        {
            isBalance = false;
        }

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    // Main function to check if tree is balanced
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return isBalance;
    }
};

int main()
{
    /*
        Test Case 1 (Balanced Tree):

              1
             / \
            2   3
           / \
          4   5

        Output: Balanced (true)
    */

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    Solution obj1;
    cout << "Tree 1 is Balanced: " << (obj1.isBalanced(root1) ? "true" : "false") << endl;

    /*
        Test Case 2 (Unbalanced Tree):

              1
             /
            2
           /
          3

        Output: Not Balanced (false)
    */

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    Solution obj2;
    cout << "Tree 2 is Balanced: " << (obj2.isBalanced(root2) ? "true" : "false") << endl;

    return 0;
}

// Output
// Tree 1 is Balanced: true
// Tree 2 is Balanced: false