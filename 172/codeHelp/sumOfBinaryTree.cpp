// GFG Problem Sum of Binary Tree

#include <bits/stdc++.h>
using namespace std;

/*
    Definition of a Binary Tree Node
*/
struct Node {
    int data;          // Value stored in the node
    Node* left;        // Pointer to left child
    Node* right;       // Pointer to right child

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to return the sum of all nodes in the binary tree
    int sumBT(Node* root) {

        // Base case:
        // Agar tree empty hai, to sum = 0
        if (root == NULL) {
            return 0;
        }

        // Left subtree ka sum nikalo
        int leftSum = sumBT(root->left);

        // Right subtree ka sum nikalo
        int rightSum = sumBT(root->right);

        // Current node ka data add karke total sum return karo
        return leftSum + rightSum + root->data;
    }
};

int main() {
    /*
        Test Case:
                1
               / \
              2   3
             / \
            4   5

        Expected Sum:
        1 + 2 + 3 + 4 + 5 = 15
    */

    // Manually tree create kar rahe hain
    Node* root = new Node(1);          // Root node
    root->left = new Node(2);          // Left child
    root->right = new Node(3);         // Right child
    root->left->left = new Node(4);    // Left child of node 2
    root->left->right = new Node(5);   // Right child of node 2

    Solution sol;

    // sumBT function call
    int result = sol.sumBT(root);

    // Result print karo
    cout << "Sum of all nodes in the binary tree: " << result << endl;

    return 0;
}
