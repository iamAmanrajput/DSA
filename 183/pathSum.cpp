// Leetcode Problem 437. Path Sum III
// Time Complexity O(N²)

#include <bits/stdc++.h>
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
    int ans = 0;

    // Yeh function ek node ko root maan ke neeche ke saare paths check karta hai
    void pathFromOneRoot(TreeNode *root, long long sum)
    {
        if (!root)
            return;

        // Agar current node ka value sum ke equal hai → ek valid path mil gaya
        if (sum == root->val)
        {
            ans++;
        }

        // Left aur right subtree me remaining sum ke saath search karo
        pathFromOneRoot(root->left, sum - root->val);
        pathFromOneRoot(root->right, sum - root->val);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        // Har node ko starting point bana ke check karo
        pathFromOneRoot(root, targetSum);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};

int main()
{
    /**
     Example Tree:

            10
           /  \
          5   -3
         / \    \
        3   2    11
       / \   \
      3  -2   1

    Target Sum = 8

    Valid paths:
    5 → 3
    5 → 2 → 1
    -3 → 11

    Answer = 3
    */

    // Tree construction
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    Solution obj;
    int targetSum = 8;

    int result = obj.pathSum(root, targetSum);

    cout << "Number of paths with sum " << targetSum << " = " << result << endl;

    return 0;
}