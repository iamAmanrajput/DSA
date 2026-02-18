// Gfg Problem Convert Binary Tree Into Sum Tree

#include <iostream>
using namespace std;

/* A binary tree node */
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:

    int helper(Node* node) {
        if (node == NULL)
            return 0;

        int leftSum = helper(node->left);
        int rightSum = helper(node->right);

        node->data = node->data + leftSum + rightSum;

        return node->data;
    }

    void toSumTree(Node *node) {
        helper(node);
    }
};

// Inorder traversal for printing tree
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    /*
            10
          /    \
        20      30
       /  \    /  \
     40   50  60   70
    */

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    Solution obj;

    cout << "Original Tree (Inorder): ";
    inorder(root);
    cout << endl;

    obj.toSumTree(root);

    cout << "After Conversion (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
