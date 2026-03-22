// Leetcode Problem 103. Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        // Edge case: agar tree empty hai
        if (!root)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        // Direction flag (true = Left to Right, false = Right to Left)
        bool LtoRdir = true;

        while (!q.empty())
        {
            int width = q.size(); // current level ka size

            // Ek level ke nodes store karne ke liye vector
            vector<int> oneLevel(width);

            for (int i = 0; i < width; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                // Zigzag ke liye index decide karna
                int index = LtoRdir ? i : width - i - 1;

                oneLevel[index] = front->val;

                // Left child push karo
                if (front->left)
                {
                    q.push(front->left);
                }

                // Right child push karo
                if (front->right)
                {
                    q.push(front->right);
                }
            }

            // Direction flip karo next level ke liye
            LtoRdir = !LtoRdir;

            // Current level answer me add karo
            ans.push_back(oneLevel);
        }

        return ans;
    }
};

int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;
    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    // Output print
    cout << "Zigzag Level Order Traversal:\n";
    for (auto level : result)
    {
        for (auto val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}