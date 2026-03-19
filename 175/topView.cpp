// GFG Problem Top View of Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Definition of a Binary Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {

        // Queue for BFS traversal
        // Stores pair of (node, horizontal distance)
        queue<pair<Node *, int>> q;

        // Map to store first node at each horizontal distance (HD)
        // key = HD, value = node->data
        map<int, int> m;

        // Push root node with HD = 0
        q.push({root, 0});

        // Perform level order traversal (BFS)
        while (q.size() > 0)
        {

            // Get front node and its HD
            Node *curr = q.front().first;
            int currHd = q.front().second;

            // If this HD is seen for the first time, store it
            // This ensures only the topmost node is stored
            if (m.find(currHd) == m.end())
            {
                m[currHd] = curr->data;
            }

            // Remove processed node from queue
            q.pop();

            // Push left child with HD - 1
            if (curr->left != NULL)
            {
                q.push({curr->left, currHd - 1});
            }

            // Push right child with HD + 1
            if (curr->right != NULL)
            {
                q.push({curr->right, currHd + 1});
            }
        }

        // Store result from map (sorted by HD automatically)
        vector<int> ans;

        for (auto it : m)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    /*
            Binary Tree:

                1
               / \
              2   3
             / \   \
            4   5   6

        Horizontal Distances:
        4(-2), 2(-1), 1(0), 3(+1), 6(+2)

        Top View = 4 2 1 3 6
    */

    // Creating tree manually
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;

    // Get top view
    vector<int> result = obj.topView(root);

    // Print result
    cout << "Top View: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}