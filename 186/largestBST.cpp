// GFG Problem Largest BST

#include <iostream>
#include <climits>
using namespace std;

/*
==================== TREE NODE ====================
*/
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/*
==================== NODE DATA CLASS ====================
Stores info for each subtree:
- size: number of nodes in subtree
- minVal: minimum value in subtree
- maxVal: maximum value in subtree
- validBST: whether subtree is BST or not
*/
class NodeData
{
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    // Default constructor
    NodeData()
    {
        size = 0;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        validBST = true;
    }

    // Parameterized constructor
    NodeData(int size, int min, int max, bool valid)
    {
        this->size = size;
        this->minVal = min;
        this->maxVal = max;
        this->validBST = valid;
    }
};

/*
==================== SOLUTION CLASS ====================
*/
class Solution
{
    NodeData findLargestBST(Node *root, int &ans)
    {

        // Base case: empty tree is a valid BST
        if (root == NULL)
        {
            return NodeData(0, INT_MAX, INT_MIN, true);
        }

        // Recursively solve for left and right subtree
        NodeData leftAns = findLargestBST(root->left, ans);
        NodeData rightAns = findLargestBST(root->right, ans);

        NodeData currNodeAns;

        // Total nodes in current subtree
        currNodeAns.size = leftAns.size + rightAns.size + 1;

        // Update max and min values
        currNodeAns.maxVal = max(root->data, rightAns.maxVal);
        currNodeAns.minVal = min(root->data, leftAns.minVal);

        /*
        Check BST condition:
        1. Left subtree must be BST
        2. Right subtree must be BST
        3. root value > max of left subtree
        4. root value < min of right subtree
        */
        if (leftAns.validBST && rightAns.validBST &&
            (root->data > leftAns.maxVal && root->data < rightAns.minVal))
        {

            currNodeAns.validBST = true;

            // Update answer (largest BST size found so far)
            ans = max(ans, currNodeAns.size);
        }
        else
        {
            currNodeAns.validBST = false;
        }

        return currNodeAns;
    }

public:
    // Returns size of largest BST in given binary tree
    int largestBst(Node *root)
    {
        int ans = 0;
        findLargestBST(root, ans);
        return ans;
    }
};

/*
==================== MAIN FUNCTION (TEST CASE) ====================
*/
int main()
{

    /*
        Example Tree:

                50
               /  \
             30    60
            /  \   / \
          5   20 45  70
                         \
                          80

        Largest BST subtree:
                60
               /  \
             45    70
                       \
                        80

        Output: 4
    */

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);

    Solution obj;
    cout << "Size of Largest BST: " << obj.largestBst(root) << endl;

    return 0;
}

// Size of Largest BST: 4