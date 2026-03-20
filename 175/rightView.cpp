// GFG Problem Right View of Binary Tree
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
    // Recursive function to get right view
    void solve(Node *root, vector<int> &ans, int level)
    {

        if (root == NULL)
        {
            return;
        }

        // If visiting level first time, store node
        if (level == ans.size())
        {
            ans.push_back(root->data);
        }

        // First go to right subtree
        solve(root->right, ans, level + 1);

        // Then go to left subtree
        solve(root->left, ans, level + 1);
    }

    vector<int> rightView(Node *root)
    {

        vector<int> ans;
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

    Expected Output (Right View):
    1 3 6
    */

    // Creating tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    vector<int> result = obj.rightView(root);

    // Printing result
    cout << "Right View: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}