// Leetcode Problem 113. Path Sum II
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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void sumHelper(TreeNode *root, int &targetSum, vector<vector<int>> &ans,
                   vector<int> &currAns, int currSum)
    {

        if (root == NULL)
            return;

        currAns.push_back(root->val);
        currSum += root->val;

        // Leaf node check
        if (root->left == NULL && root->right == NULL)
        {
            if (currSum == targetSum)
            {
                ans.push_back(currAns);
            }
        }

        sumHelper(root->left, targetSum, ans, currAns, currSum);
        sumHelper(root->right, targetSum, ans, currAns, currSum);

        currAns.pop_back(); // backtracking
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> currAns;

        sumHelper(root, targetSum, ans, currAns, 0);
        return ans;
    }
};

int main()
{
    /*
        Test Case Tree:
                5
               / \
              4   8
             /   / \
            11  13  4
           /  \     / \
          7    2   5   1

        Target Sum = 22

        Expected Output:
        [5,4,11,2]
        [5,8,4,5]
    */

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution obj;
    int targetSum = 22;

    vector<vector<int>> result = obj.pathSum(root, targetSum);

    // Print result
    cout << "Paths with sum " << targetSum << ":\n";
    for (auto path : result)
    {
        cout << "[ ";
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}