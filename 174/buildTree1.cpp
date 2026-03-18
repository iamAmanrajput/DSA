// GFG Problem Construct Tree from Inorder & Preorder

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

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    //  Step 1: Create mapping of value -> index (for inorder)
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }

    //  Step 2: Recursive function to build tree
    Node *solve(vector<int> &inorder, vector<int> &preorder,
                int &index, int inorderStart, int inorderEnd,
                int n, map<int, int> &nodeToIndex)
    {

        // Base case
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        // Preorder gives root
        int element = preorder[index++];
        Node *root = new Node(element);

        // Find position of root in inorder
        int position = nodeToIndex[element];

        //  Build left subtree
        root->left = solve(inorder, preorder, index,
                           inorderStart, position - 1,
                           n, nodeToIndex);

        //  Build right subtree
        root->right = solve(inorder, preorder, index,
                            position + 1, inorderEnd,
                            n, nodeToIndex);

        return root;
    }

    // Main build function
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = inorder.size();

        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);

        int preorderIndex = 0;

        return solve(inorder, preorder, preorderIndex, 0, n - 1, n, nodeToIndex);
    }
};

// Helper function to print tree (Inorder Traversal)
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
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    Solution obj;
    Node *root = obj.buildTree(inorder, preorder);

    // 🔹 Output check (should match inorder)
    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);

    return 0;
}
