// GFG : Flattening a Linked List
// Recursive Approach

#include <iostream>
using namespace std;

// Node structure used in the program
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    // Recursively merge two sorted bottom-linked lists
    Node *merge(Node *a, Node *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;

        Node *ans = NULL;
        if (a->data < b->data)
        {
            ans = a;
            ans->bottom = merge(a->bottom, b);
        }
        else
        {
            ans = b;
            ans->bottom = merge(a, b->bottom);
        }
        return ans;
    }

    // Function which returns the root of the flattened linked list
    Node *flatten(Node *root)
    {
        if (!root)
            return NULL;
        // Merge current list with flattened next list
        Node *mergedLL = merge(root, flatten(root->next));
        return mergedLL;
    }
};

// Helper function to print a bottom-linked list
void printBottomList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Helper function to create a sample multilevel linked list
Node *createSampleList()
{
    /*
       We are creating this linked list:

       5 -> 10 -> 19 -> 28
       |     |     |     |
       7     20    22    35
       |           |     |
       8           50    40
       |                 |
       30                45
    */

    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    return head;
}

int main()
{
    // Create the multilevel linked list
    Node *root = createSampleList();

    // Flatten the linked list
    Solution s;
    Node *flat = s.flatten(root);

    // Print the flattened linked list
    cout << "Flattened linked list: ";
    printBottomList(flat);

    return 0;
}

// Flattened linked list: 5 7 8 10 19 20 22 28 30 35 40 45 50
