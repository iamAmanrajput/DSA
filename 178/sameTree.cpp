// Leetcode Problem 100. Same Tree

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        // Case 1: Both nodes are NULL
        if (p == NULL && q == NULL)
        {
            return true;
        }

        // Case 2: One is NULL, the other is not
        if (p == NULL && q != NULL)
        {
            return false;
        }

        if (p != NULL && q == NULL)
        {
            return false;
        }

        // Case 3: Values are different
        if (p->val != q->val)
        {
            return false;
        }

        // Case 4: Check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    /*
        Tree 1:
              1
             / \
            2   3

        Tree 2:
              1
             / \
            2   3
    */

    // Tree 1
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;
    bool result = obj.isSameTree(p, q);

    if (result)
    {
        cout << "Trees are SAME " << endl;
    }
    else
    {
        cout << "Trees are NOT SAME " << endl;
    }

    return 0;
}