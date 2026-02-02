// Leetcode Problem 110. Balanced Binary Tree
// TC O(n^2)
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Helper function to calculate the maximum depth of a tree
    int height(TreeNode *root)
    {
        // Base Case: An empty tree has height 0
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Height is 1 (current node) + the max height of its children
        int ans = 1 + max(leftHeight, rightHeight);
        return ans;
    }

    bool isBalanced(TreeNode *root)
    {
        // Base Case: An empty tree is always balanced
        if (root == NULL)
        {
            return true;
        }

        // 1. Check if the current node is balanced
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool ans1 = (diff <= 1);

        // 2. Recursively check if the left and right subtrees are balanced
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        // A tree is balanced only if current node, left subtree, and right subtree are all balanced
        if (ans1 && leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// --- Test Case Implementation ---
int main()
{
    Solution sol;

    /* Creating a balanced tree:
            1
           / \
          2   3
         /
        4
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    if (sol.isBalanced(root))
    {
        cout << "The tree is balanced!" << endl;
    }
    else
    {
        cout << "The tree is not balanced!" << endl;
    }

    return 0;
}