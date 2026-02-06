// Leetcode Problem 543. Diameter of Binary Tree
// TC - O(N)

#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;         // Node value
    TreeNode *left;  // Pointer to left child
    TreeNode *right; // Pointer to right child

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans = 0; // Stores maximum diameter found so far

    // Function to calculate height and update diameter
    int height(TreeNode *root)
    {
        // Base case: empty node
        if (root == NULL)
        {
            return 0;
        }

        // Height of left subtree
        int leftHeight = height(root->left);

        // Height of right subtree
        int rightHeight = height(root->right);

        // Update diameter at current node
        ans = max(leftHeight + rightHeight, ans);

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    // Function to return diameter of binary tree
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root); // Single traversal
        return ans;
    }
};

int main()
{
    /*
        Test Case:
                1
               / \
              2   3
             / \
            4   5

        Longest path: 4 -> 2 -> 1 -> 3
        Diameter (edges) = 3
    */

    // Manually creating the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;

    // Calculate diameter
    int result = sol.diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree: " << result << endl;

    return 0;
}
