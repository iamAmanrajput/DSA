// Leetcode Problem 100 Same Tree

#include <bits/stdc++.h>
using namespace std;

/*
    Definition of a Binary Tree Node
*/
struct TreeNode
{
    int val;         // Node ki value
    TreeNode *left;  // Left child pointer
    TreeNode *right; // Right child pointer

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value, left child and right child
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to check whether two binary trees are same or not
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        // Case 1: Dono nodes NULL hain
        // Matlab dono trees yahin end ho gaye → same
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        // Case 2: Ek NULL hai aur doosra nahi
        // Structure different ho gaya
        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        // Case 3: Dono nodes ki values different hain
        if (p->val != q->val)
        {
            return false;
        }

        // Case 4: Left aur Right subtree ko recursively check karo
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main()
{
    /*
        Test Case 1 (Same Trees):
                1                1
               / \              / \
              2   3            2   3

        Expected Output: true
    */

    // Tree p
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree q
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;

    cout << "Are trees p and q same? "
         << (sol.isSameTree(p, q) ? "Yes" : "No") << endl;

    /*
        Test Case 2 (Different Trees):
                1                1
               /                  \
              2                    2

        Expected Output: false
    */

    TreeNode *p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode *q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    cout << "Are trees p2 and q2 same? "
         << (sol.isSameTree(p2, q2) ? "Yes" : "No") << endl;

    return 0;
}
