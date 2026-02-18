// Leetcode Problem 236. Lowest Common Ancestor of a Binary Tree

#include <iostream>
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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // Base Case: If tree ends
        if (root == NULL)
        {
            return NULL;
        }

        // If current node matches p, return p
        if (root->val == p->val)
        {
            return p;
        }

        // If current node matches q, return q
        if (root->val == q->val)
        {
            return q;
        }

        // Recursively search in left subtree
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);

        // Recursively search in right subtree
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        // If both sides return NULL → not found
        if (leftAns == NULL && rightAns == NULL)
        {
            return NULL;
        }

        // If only left side returned non-NULL
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }

        // If only right side returned non-NULL
        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }

        // If both sides returned non-NULL → current node is LCA
        else
        {
            return root;
        }
    }
};

int main()
{

    /*
            3
          /   \
         5     1
        / \   / \
       6   2 0   8
          / \
         7   4
    */

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;

    // Test Case 1: LCA of 5 and 1 → should be 3
    TreeNode *p = root->left;  // Node 5
    TreeNode *q = root->right; // Node 1

    TreeNode *ans = obj.lowestCommonAncestor(root, p, q);

    if (ans != NULL)
        cout << "LCA of " << p->val << " and " << q->val << " is: " << ans->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}

// Output
// LCA of 5 and 1 is: 3
