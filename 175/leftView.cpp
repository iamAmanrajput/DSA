// GFG Problem Left View of Binary Tree
// TC = O(n)
// SC = O(n)

#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

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
    // Recursive function to get left view
    void solve(Node *root, vector<int> &ans, int level)
    {

        // Base case: if node is null, return
        if (root == NULL)
        {
            return;
        }

        // If we are visiting this level for the first time
        // then push the current node's data
        if (level == ans.size())
        {
            ans.push_back(root->data);
        }

        // First go to left subtree
        solve(root->left, ans, level + 1);

        // Then go to right subtree
        solve(root->right, ans, level + 1);
    }

    vector<int> leftView(Node *root)
    {

        vector<int> ans;

        // Start from level 0
        int level = 0;

        solve(root, ans, level);

        return ans;
    }
};

int main()
{

    /*
    -------------------- Test Case --------------------

    Tree:
                1
              /   \
             2     3
            / \     \
           4   5     6
    */

    // Creating tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    vector<int> result = obj.leftView(root);

    // Printing result
    cout << "Left View: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

// Left View: 1 2 4