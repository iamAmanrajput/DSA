// Leetcode problem 102. Binary Tree Level Order Traversal
// Iteration Method 
// TC - O(n)

#include <iostream>
#include <queue>
using namespace std;

/* Binary Tree Node */
struct Node
{
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

void levelOrderPrint(Node *root)
{

    // Agar tree empty hai
    if (root == NULL)
        return;

    queue<Node *> q;

    // Step 1: root push karo
    q.push(root);

    // Step 2: level end marker
    q.push(NULL);

    // Step 3: jab tak queue empty na ho
    while (!q.empty())
    {

        Node *curr = q.front();
        q.pop();

        // Agar NULL mila → level complete
        if (curr == NULL)
        {
            cout << endl; // next line for next level

            // Agar queue empty nahi hai
            if (!q.empty())
            {
                q.push(NULL); // next level ke liye marker
            }
        }
        else
        {
            // Normal node print
            cout << curr->data << " ";

            // Left child
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            // Right child
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{

    /*
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    levelOrderPrint(root);

    return 0;
}

// Output
// 1
// 2 3
// 4 5 6
