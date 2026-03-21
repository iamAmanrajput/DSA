// GFG Problem Diagonal Tree Traversal
// Optimized Approach

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* A binary tree node */
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<int> diagonal(Node *root)
    {

        // Result vector to store diagonal traversal
        vector<int> ans;

        // If tree is empty, return empty vector
        if (!root)
        {
            return ans;
        }

        // Queue to store left children (next diagonals)
        queue<Node *> q;
        q.push(root);

        // Process until queue becomes empty
        while (!q.empty())
        {

            // Take front node from queue
            Node *temp = q.front();
            q.pop();

            // Traverse current diagonal
            while (temp)
            {

                // Add current node's data
                ans.push_back(temp->data);

                // If left child exists, push into queue
                // It will be processed in next diagonal
                if (temp->left)
                {
                    q.push(temp->left);
                }

                // Move to right child (same diagonal)
                temp = temp->right;
            }
        }

        return ans;
    }
};

int main()
{

    /*
        Test Tree:

                8
              /   \
             3     10
            / \      \
           1   6      14
              / \     /
             4   7   13

        Expected Diagonal Traversal:
        8 10 14 3 6 7 13 1 4
    */

    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Solution obj;
    vector<int> result = obj.diagonal(root);

    // Print result
    cout << "Diagonal Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}