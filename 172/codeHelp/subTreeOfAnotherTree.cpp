// Leetcode Problem 572. Subtree of Another Tree

#include <bits/stdc++.h>
using namespace std;

/*
    Definition of a Binary Tree Node
*/
struct TreeNode
{
    int val;         // Node ki value
    TreeNode *left;  // Left child
    TreeNode *right; // Right child

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Helper function:
    // Check karta hai ki dono trees exactly same hain ya nahi
    bool isSameTree(TreeNode *root, TreeNode *subRoot)
    {

        // Case 1: Dono NULL hain → same tree
        if (root == NULL && subRoot == NULL)
        {
            return true;
        }

        // Case 2: Ek NULL hai, doosra nahi → different
        if (root == NULL || subRoot == NULL)
        {
            return false;
        }

        // Case 3: Node values match nahi karti
        if (root->val != subRoot->val)
        {
            return false;
        }

        // Case 4: Left aur Right subtree recursively check karo
        return isSameTree(root->left, subRoot->left) &&
               isSameTree(root->right, subRoot->right);
    }

    // Main function:
    // Check karta hai ki subRoot, root ka subtree hai ya nahi
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {

        // Agar main tree NULL ho gaya
        // to subtree sirf tab possible hai jab subRoot bhi NULL ho
        if (root == NULL)
        {
            return subRoot == NULL;
        }

        // Agar current node se same tree mil gaya
        if (isSameTree(root, subRoot))
        {
            return true;
        }

        // Warna left ya right subtree me search karo
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main()
{
    /*
        Test Case 1:
        Root Tree:
                3
               / \
              4   5
             / \
            1   2

        SubRoot:
              4
             / \
            1   2

        Expected Output: true
    */

    // Root tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // SubRoot tree
    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;

    cout << "Is subRoot a subtree of root? "
         << (sol.isSubtree(root, subRoot) ? "Yes" : "No") << endl;

    /*
        Test Case 2:
        SubRoot:
              4
               \
                2

        Expected Output: false
    */

    TreeNode *subRoot2 = new TreeNode(4);
    subRoot2->right = new TreeNode(2);

    cout << "Is subRoot2 a subtree of root? "
         << (sol.isSubtree(root, subRoot2) ? "Yes" : "No") << endl;

    return 0;
}
