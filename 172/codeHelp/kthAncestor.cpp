// Kth Ancestor

#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
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

// Build Tree Function
Node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Enter data for left part of " << data << " node" << endl;
    root->left = buildTree();

    cout << "Enter data for right part of " << data << " node" << endl;
    root->right = buildTree();

    return root;
}

// Function to find Kth Ancestor
bool KthAncestor(Node *root, int &k, int p, int &ans)
{
    if (root == NULL)
        return false;

    if (root->data == p)
        return true;

    bool leftAns = KthAncestor(root->left, k, p, ans);
    bool rightAns = KthAncestor(root->right, k, p, ans);

    if (leftAns || rightAns)
    {
        k--;

        if (k == 0)
        {
            ans = root->data; // store answer
            return false;     // stop recursion
        }

        return true;
    }

    return false;
}

/*
Tree:
        1
       / \
      2   3
     / \
    4   5

Input:
1 2 4 -1 -1 5 -1 -1 3 -1 -1

Test Case 1:
k = 1, p = 4
Output: 2

Test Case 2:
k = 2, p = 4
Output: 1

Test Case 3:
k = 3, p = 4
Output: -1 (ancestor exist nahi karta)
*/

int main()
{
    Node *root = NULL;
    root = buildTree();

    int k = 1;
    int p = 4;
    int ans = -1;

    KthAncestor(root, k, p, ans);

    // FINAL PRINT (always print)
    if (ans == -1)
    {
        cout << "Answer: -1 (No such ancestor)" << endl;
    }
    else
    {
        cout << "Answer: " << ans << endl;
    }

    return 0;
}