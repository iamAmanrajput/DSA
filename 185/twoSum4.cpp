// Leetcode Problem 653. Two Sum IV - Input is a BST

#include <iostream>
#include <vector>
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
    // Inorder traversal to store BST elements in sorted order
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    // Main logic: two pointer on sorted array
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        int start = 0;
        int end = inorder.size() - 1;

        while (start < end)
        {
            int sum = inorder[start] + inorder[end];

            if (sum == k)
            {
                return true;
            }
            else if (sum > k)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return false;
    }
};

// Helper function to create a sample BST
TreeNode *createSampleTree()
{
    /*
            5
           / \
          3   6
         / \   \
        2   4   7
    */
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    return root;
}

int main()
{
    Solution obj;

    // Create test BST
    TreeNode *root = createSampleTree();

    // Test cases
    int k1 = 9;  // Expected: true (2 + 7 or 3 + 6)
    int k2 = 28; // Expected: false

    // Run function
    cout << "Result for k = 9: " << (obj.findTarget(root, k1) ? "true" : "false") << endl;
    cout << "Result for k = 28: " << (obj.findTarget(root, k2) ? "true" : "false") << endl;

    return 0;
}

// Result for k = 9: true
// Result for k = 28: false