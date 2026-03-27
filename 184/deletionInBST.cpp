// Leetcode Problem 450. Delete Node in a BST

#include <iostream>
#include <queue>
using namespace std;

// Node class representing each node of BST
class Node
{
public:
    int data;    // value stored in node
    Node *left;  // pointer to left child
    Node *right; // pointer to right child

    // Constructor to initialize node with given data
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert a node into BST
Node *insertIntoBST(Node *root, int data)
{
    // Base case: if root is NULL, create a new node
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // If data is smaller than root, insert into left subtree
    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // If data is greater or equal, insert into right subtree
        root->right = insertIntoBST(root->right, data);
    }

    return root; // return updated root
}

// Function to take input and build BST
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    // Continue inserting until user enters -1
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Function to print tree in Level Order (Breadth First Traversal)
void levelOrderPrint(Node *root)
{
    // If tree is empty, return
    if (root == NULL)
        return;

    queue<Node *> q;

    // Step 1: Push root node into queue
    q.push(root);

    // Step 2: Push NULL as level separator
    q.push(NULL);

    // Step 3: Traverse until queue becomes empty
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // If NULL encountered, it means end of current level
        if (curr == NULL)
        {
            cout << endl; // move to next line for next level

            // If queue still has nodes, add another NULL marker
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // Print current node data
            cout << curr->data << " ";

            // Push left child if exists
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            // Push right child if exists
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

// Function to find a node in BST
Node *findNodeInBST(Node *root, int target)
{

    // Base case: if tree is empty
    if (root == NULL)
    {
        return NULL;
    }

    // If target is found
    if (root->data == target)
    {
        return root;
    }

    // If target is greater, search in right subtree
    if (target > root->data)
    {
        return findNodeInBST(root->right, target);
    }
    // If target is smaller, search in left subtree
    else
    {
        return findNodeInBST(root->left, target);
    }
}

// Function to find Maximum Value in BST
int maxVal(Node *root)
{
    Node *temp = root;

    // If tree is empty
    if (temp == NULL)
    {
        return -1;
    }

    // Move to the rightmost node
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    // Return maximum value
    return temp->data;
}

// Deletion In BST
Node *deleteNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // 4 Cases
        if (root->left == NULL && root->right == NULL)
        {
            // Leaf Node
            delete root;
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            delete root;
            return child;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            delete root;
            return child;
        }
        else
        {
            // Exists Both Child
            // Find Inorder predecessor in left subtree
            int inorderPred = maxVal(root->left);
            // replace root->data with inorder predecessor
            root->data = inorderPred;
            // delete inorder predecessor from left subtree
            root->left = deleteNodeInBST(root->left, inorderPred);
            return root;
        }
    }
    else if (target > root->data)
    {
        // Go Right
        root->right = deleteNodeInBST(root->right, target);
    }
    else if (target < root->data)
    {
        // Go Left
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data for nodes (-1 to stop):" << endl;

    // Build BST from user input
    takeInput(root);

    cout << "Level Order Traversal of BST:" << endl;

    // Print BST level by level
    levelOrderPrint(root);

    // delete node
    root = deleteNodeInBST(root, 100);
    levelOrderPrint(root);

    return 0;
}

/*
==================== SAMPLE INPUT ====================

Enter the data for nodes (-1 to stop):
50 30 70 20 40 60 80 -1

(Delete target is fixed in code: 100)

==================== TREE STRUCTURE ====================

        50
       /  \
     30    70
    / \   / \
  20  40 60 80


==================== OUTPUT ====================

Level Order Traversal of BST:
50
30 70
20 40 60 80

After Deleting 100:
50
30 70
20 40 60 80

(Note: 100 does not exist, so tree remains same)

========================================================
*/