// GFG Problem Binary Tree from Inorder and Postorder

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Node Structure
*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    // Create mapping of node value to its index in inorder traversal
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }

    // Recursive function to construct tree
    Node *solve(vector<int> &inorder, vector<int> &postorder,
                int &index, int inorderStart, int inorderEnd,
                int n, map<int, int> &nodeToIndex)
    {

        // Base case
        if (index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        // Postorder gives root from end
        int element = postorder[index--];
        Node *root = new Node(element);

        // Find position of root in inorder
        int position = nodeToIndex[element];

        // Important: build right subtree first
        root->right = solve(inorder, postorder, index,
                            position + 1, inorderEnd,
                            n, nodeToIndex);

        // Then build left subtree
        root->left = solve(inorder, postorder, index,
                           inorderStart, position - 1,
                           n, nodeToIndex);

        return root;
    }

    // Main function to build tree
    Node *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = inorder.size();

        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);

        int postorderIndex = n - 1;

        return solve(inorder, postorder, postorderIndex, 0, n - 1, n, nodeToIndex);
    }
};

// Function to print inorder traversal
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{

    // Test Case
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};

    Solution obj;
    Node *root = obj.buildTree(inorder, postorder);

    // Output should match inorder
    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);

    return 0;
}