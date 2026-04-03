// GFG Problem Is Binary Tree Heap


#include <iostream>
using namespace std;

// Node structure for binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Step 1: Count total nodes in tree
    int countNode(Node *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }

        // count = left subtree + right subtree + current node
        return 1 + countNode(root->left) + countNode(root->right);
    }

    // Step 2: Check Complete Binary Tree using indexing
    bool isCBT(Node *root, int index, int totalNodeCount)
    {
        // empty tree is valid CBT
        if (root == NULL)
        {
            return true;
        }

        // if index goes out of total nodes, not complete
        if (index >= totalNodeCount)
        {
            return false;
        }

        // check left and right subtree
        bool left = isCBT(root->left, 2 * index + 1, totalNodeCount);
        bool right = isCBT(root->right, 2 * index + 2, totalNodeCount);

        return left && right;
    }

    // Step 3: Check Max Heap Property
    bool isMaxOrder(Node *root)
    {
        // leaf node always satisfies heap property
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        // only left child exists
        if (root->right == NULL)
        {
            return (root->data >= root->left->data);
        }

        // both children exist
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        // check current node with children + recursive result
        return (left && right &&
                root->data >= root->left->data &&
                root->data >= root->right->data);
    }

    // Final function to check if tree is heap
    bool isHeap(Node *tree)
    {
        int index = 0;

        // total nodes count
        int totalCount = countNode(tree);

        // check both CBT and Max Heap property
        if (isCBT(tree, index, totalCount) && isMaxOrder(tree))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution obj;

    // Test Case 1: Valid Max Heap
    Node *root1 = new Node(10);
    root1->left = new Node(9);
    root1->right = new Node(8);
    root1->left->left = new Node(7);
    root1->left->right = new Node(6);

    // structure:
    //        10
    //       /  \
    //      9    8
    //     / \
    //    7   6

    if (obj.isHeap(root1))
    {
        cout << "Tree 1 is a Max Heap" << endl;
    }
    else
    {
        cout << "Tree 1 is NOT a Max Heap" << endl;
    }

    // Test Case 2: Not a Max Heap (heap property fails)
    Node *root2 = new Node(10);
    root2->left = new Node(15); // violation: child > parent
    root2->right = new Node(8);

    // structure:
    //      10
    //     /  \
    //   15    8

    if (obj.isHeap(root2))
    {
        cout << "Tree 2 is a Max Heap" << endl;
    }
    else
    {
        cout << "Tree 2 is NOT a Max Heap" << endl;
    }

    // Test Case 3: Not Complete Binary Tree
    Node *root3 = new Node(10);
    root3->left = new Node(9);
    root3->right = new Node(8);
    root3->right->left = new Node(7); // gap on left side

    // structure:
    //        10
    //       /  \
    //      9    8
    //           /
    //          7

    if (obj.isHeap(root3))
    {
        cout << "Tree 3 is a Max Heap" << endl;
    }
    else
    {
        cout << "Tree 3 is NOT a Max Heap" << endl;
    }

    return 0;
}