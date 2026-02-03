// Leetcode Problem 104. Maximum Depth of Binary Tree
// TC - O(n)
// using postorder traversal

#include <bits/stdc++.h>
using namespace std;

/*
 Definition of a Binary Tree Node
*/
struct TreeNode
{
    int val;         // Node ki value
    TreeNode *left;  // Left child pointer
    TreeNode *right; // Right child pointer

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value + left + right
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to calculate maximum depth (height) of binary tree
    int maxDepth(TreeNode *root)
    {
        // Base case:
        // Agar tree empty hai to depth = 0
        if (root == NULL)
        {
            return 0;
        }

        // Left subtree ki depth nikal lo
        int leftDepth = maxDepth(root->left);

        // Right subtree ki depth nikal lo
        int rightDepth = maxDepth(root->right);

        // Dono me se max lo aur current node ke liye +1
        return max(leftDepth, rightDepth) + 1;
    }
};

int main()
{
    /*
        Test Case:
                1
               / \
              2   3
             /
            4

        Expected Output:
        Max Depth = 3
    */

    // Tree manually create kar rahe hain
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;

    // Function call
    int depth = sol.maxDepth(root);

    cout << "Max Depth of Binary Tree is: " << depth << endl;

    return 0;
}
