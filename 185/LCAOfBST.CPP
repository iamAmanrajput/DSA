// Leetcode Problem 235. Lowest Common Ancestor of a Binary Search Tree

#include <iostream>
using namespace std;

/*
==================== TREE NODE ====================
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

/*
==================== SOLUTION CLASS ====================
*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base case
        if (root == NULL)
        {
            return NULL;
        }

        // If both nodes are smaller than root → go left
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both nodes are greater than root → go right
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Otherwise current root is LCA
        return root;
    }
};

/*
==================== MAIN FUNCTION ====================
*/
int main()
{
    /*
        BST Structure:

                6
              /   \
             2     8
            / \   / \
           0   4 7   9
              / \
             3   5
    */

    // Creating nodes
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Nodes for which we find LCA
    TreeNode *p = root->left;        // Node 2
    TreeNode *q = root->left->right; // Node 4

    // Solution object
    Solution obj;

    // Finding LCA
    TreeNode *lca = obj.lowestCommonAncestor(root, p, q);

    // Output result
    if (lca != NULL)
    {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    }
    else
    {
        cout << "LCA not found" << endl;
    }

    return 0;
}

// Lowest Common Ancestor: 2