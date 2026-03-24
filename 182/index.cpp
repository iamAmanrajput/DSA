// Leetcode Problem 987. Vertical Order Traversal of a Binary Tree
// Time Complexity O(N log N)
// Space Complexity O(N)

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;

        // Queue will store node along with its (row, col)
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        // Map structure:
        // col -> { row -> multiset of node values }
        map<int, map<int, multiset<int>>> mp;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            TreeNode *node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            // Insert node value at correct column and row
            mp[col][row].insert(node->val);

            // Traverse left child
            if (node->left)
            {
                q.push({node->left, {row + 1, col - 1}});
            }

            // Traverse right child
            if (node->right)
            {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        // Construct final answer from map
        for (auto it : mp)
        {
            vector<int> vLine;

            for (auto colMapIt : it.second)
            {
                auto &mset = colMapIt.second;

                // Insert all elements from multiset (already sorted)
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }

            ans.push_back(vLine);
        }

        return ans;
    }
};

int main()
{
    /*
        Test Case:

                3
               / \
              9  20
                 / \
                15  7

        Expected Output:
        [[9], [3,15], [20], [7]]
    */

    // Creating tree manually
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> result = obj.verticalTraversal(root);

    // Print result
    cout << "Vertical Order Traversal:" << endl;
    for (auto &col : result)
    {
        cout << "[ ";
        for (auto val : col)
        {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}