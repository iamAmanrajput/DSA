// Leetcode Problem 543. Diameter of Binary Tree
// TC - O(N^2)


#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;         // Node ka value
    TreeNode *left;  // Left child pointer
    TreeNode *right; // Right child pointer

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
    // Function to calculate height of binary tree
    int height(TreeNode *root)
    {
        // Base case: empty tree ki height 0 hoti hai
        if (root == NULL)
        {
            return 0;
        }

        // Left subtree ki height
        int leftHeight = height(root->left);

        // Right subtree ki height
        int rightHeight = height(root->right);

        // Max height + 1 (current node)
        return max(leftHeight, rightHeight) + 1;
    }

    // Function to calculate diameter of binary tree
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Base case
        if (root == NULL)
        {
            return 0;
        }

        // Left subtree ka diameter
        int leftDiam = diameterOfBinaryTree(root->left);

        // Right subtree ka diameter
        int rightDiam = diameterOfBinaryTree(root->right);

        // Current node ka diameter
        // (left subtree height + right subtree height)
        int currDiam = height(root->left) + height(root->right);

        // Maximum diameter return karo
        return max(currDiam, max(leftDiam, rightDiam));
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

        Diameter = path 4 -> 2 -> 1 -> 3
        Number of edges = 3
    */

    // Tree manually create kar rahe hain
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;

    // Diameter calculate karo
    int diameter = sol.diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree: " << diameter << endl;

    return 0;
}
