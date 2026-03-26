// GFG Problem Minimum in BST

#include <bits/stdc++.h>
using namespace std;

/*
Structure of a Binary Tree Node
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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    // Function to find minimum value in BST
    int minValue(Node *root)
    {
        // BST me minimum value leftmost node me hoti hai

        while (true)
        {
            // Agar left child nahi hai, to current node hi minimum hai
            if (root->left == NULL)
            {
                return root->data;
            }
            else
            {
                // Left side move karte jao
                root = root->left;
            }
        }
    }
};

int main()
{
    /*
        Test Case:
                10
               /  \
              5    20
             / \
            2   8

        Minimum value = 2
    */

    // Tree create karte hain manually
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);

    Solution obj;

    // Function call
    int ans = obj.minValue(root);

    cout << "Minimum value in BST is: " << ans << endl;

    return 0;
}