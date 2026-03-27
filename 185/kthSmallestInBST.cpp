// Leetcode 230. Kth Smallest Element in a BST

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val = x;
        this->left = left;
        this->right = right;
    }
};

/*
==================== SOLUTION CLASS ====================
*/
class Solution
{
public:
    // Function to find kth smallest element in BST
    int kthSmallest(TreeNode *root, int &k)
    {
        // Base case
        if (!root)
            return -1;

        // Step 1: Traverse left subtree
        int left = kthSmallest(root->left, k);

        // If answer already found in left subtree
        if (k == 0)
            return left;

        // Step 2: Process current node
        k--;
        if (k == 0)
            return root->val;

        // Step 3: Traverse right subtree
        return kthSmallest(root->right, k);
    }
};

/*
==================== MAIN FUNCTION ====================
*/
int main()
{
    /*
        BST Structure:

                5
              /   \
             3     6
            / \
           2   4
          /
         1
    */

    // Creating BST
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    // Value of k
    int k = 3;

    // Solution object
    Solution obj;

    // Finding kth smallest element
    int result = obj.kthSmallest(root, k);

    // Output result
    cout << "Kth Smallest Element: " << result << endl;

    return 0;
}