// Leetcode Problem 98. Validate Binary Search Tree

#include <iostream>
#include <climits>
using namespace std;

/*
==================== TREE NODE ====================
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

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
    bool solve(TreeNode *root, long long lb, long long ub)
    {
        if (root == NULL)
        {
            return true;
        }

        // Check if current node is in valid range
        if (root->val > lb && root->val < ub)
        {
            return solve(root->left, lb, root->val) &&
                   solve(root->right, root->val, ub);
        }
        else
        {
            return false;
        }
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

/*
==================== MAIN FUNCTION ====================
*/
int main()
{

    Solution obj;

    /*
    ==================== TEST CASE 1 (VALID BST) ====================

            5
           / \
          3   7
         / \   \
        2   4   8

    Expected Output: VALID BST
    */

    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(8);

    if (obj.isValidBST(root1))
        cout << "Test Case 1: VALID BST" << endl;
    else
        cout << "Test Case 1: NOT A BST" << endl;

    /*
    ==================== TEST CASE 2 (INVALID BST) ====================

            5
           / \
          3   7
             /
            4   (4 < 5 but in right subtree)

    Expected Output: NOT A BST
    */

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);

    if (obj.isValidBST(root2))
        cout << "Test Case 2: VALID BST" << endl;
    else
        cout << "Test Case 2: NOT A BST" << endl;

    /*
    ==================== TEST CASE 3 (EDGE CASE) ====================

    Single Node Tree:
            10

    Expected Output: VALID BST
    */

    TreeNode *root3 = new TreeNode(10);

    if (obj.isValidBST(root3))
        cout << "Test Case 3: VALID BST" << endl;
    else
        cout << "Test Case 3: NOT A BST" << endl;

    return 0;
}