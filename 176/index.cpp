// Leetcode Problem 543. Diameter of Binary Tree
// Optimized Code
// TC -> O(n)

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int Diameter = 0;

    // Function to calculate height and update diameter
    int height(TreeNode* root) {
        // Base case
        if (root == NULL) {
            return 0;
        }

        // Recursively get height of left and right subtree
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Diameter at current node = leftHeight + rightHeight
        int currDiameter = leftHeight + rightHeight;

        // Update global diameter
        Diameter = max(currDiameter, Diameter);

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);  // Start DFS
        return Diameter;
    }
};

int main() {
    /*
        Test Case Tree:

              1
             / \
            2   3
           / \
          4   5

        Diameter = 3 (path: 4 -> 2 -> 1 -> 3 OR 5 -> 2 -> 1 -> 3)
    */

    // Creating nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Solution object
    Solution obj;

    // Calculate diameter
    int result = obj.diameterOfBinaryTree(root);

    // Output result
    cout << "Diameter of Binary Tree: " << result << endl;

    return 0;
}