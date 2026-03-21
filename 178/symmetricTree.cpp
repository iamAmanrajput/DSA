// Leetcode Problem 101. Symmetric Tree

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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Helper function to check symmetry
    bool solve(TreeNode *p, TreeNode *q)
    {

        // Case 1: both nodes are NULL
        if (p == NULL && q == NULL)
        {
            return true;
        }

        // Case 2: one is NULL, other is not
        if (p == NULL || q == NULL)
        {
            return false;
        }

        // Case 3: values are different
        if (p->val != q->val)
        {
            return false;
        }

        // Case 4: check mirror condition
        return solve(p->left, q->right) && solve(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;

        TreeNode *p = root->left;
        TreeNode *q = root->right;

        return solve(p, q);
    }
};

int main()
{

    /*
        Test Case 1 (Symmetric Tree)

              1
            /   \
           2     2
          / \   / \
         3   4 4   3
    */

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root1))
    {
        cout << "Tree 1 is Symmetric" << endl;
    }
    else
    {
        cout << "Tree 1 is Not Symmetric" << endl;
    }

    /*
        Test Case 2 (Not Symmetric)

              1
            /   \
           2     2
            \     \
             3     3
    */

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    if (obj.isSymmetric(root2))
    {
        cout << "Tree 2 is Symmetric" << endl;
    }
    else
    {
        cout << "Tree 2 is Not Symmetric" << endl;
    }

    return 0;
}