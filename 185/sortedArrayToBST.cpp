// Leetcode Problem 108. Convert Sorted Array to Binary Search Tree

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
    // Recursive function to build BST from sorted array
    TreeNode *solve(vector<int> &nums, int s, int e)
    {
        // Base case: invalid range
        if (s > e)
        {
            return NULL;
        }

        // Find middle element (root of current subtree)
        int mid = (s + e) / 2;
        int element = nums[mid];

        // Create root node
        TreeNode *root = new TreeNode(element);

        // Recursively build left subtree
        root->left = solve(nums, s, mid - 1);

        // Recursively build right subtree
        root->right = solve(nums, mid + 1, e);

        return root;
    }

    // Main function
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};

// Function to print inorder traversal (for checking correctness)
void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    // Test case: sorted array
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution obj;

    // Convert sorted array to BST
    TreeNode *root = obj.sortedArrayToBST(nums);

    // Print inorder traversal of constructed BST
    // Expected output should be same as input array (sorted)
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}