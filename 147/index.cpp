// GFG : Delete N nodes after M nodes of a linked list

#include <bits/stdc++.h>
using namespace std;

/*
   Node definition
*/
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Recursive function to delete n nodes after m nodes
    Node *linkdelete(Node *head, int n, int m)
    {
        if (!head)
            return NULL; // base case

        Node *curr = head;

        // 1. Skip m-1 nodes (move curr forward)
        for (int i = 1; i < m && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr == NULL)
            return head;

        // 2. Start deleting next n nodes
        Node *temp = curr->next;
        for (int i = 0; i < n && temp != NULL; i++)
        {
            Node *del = temp;
            temp = temp->next;
            delete del; // free memory
        }

        // 3. Connect current node to the node after deleted part
        curr->next = linkdelete(temp, n, m);

        return head;
    }
};

/* Utility function to print linked list */
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* Utility function to create linked list from vector */
Node *createList(vector<int> vals)
{
    if (vals.empty())
        return NULL;
    Node *head = new Node(vals[0]);
    Node *curr = head;
    for (int i = 1; i < vals.size(); i++)
    {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    // Example input
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = createList(vals);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    int m = 2, n = 2;
    head = obj.linkdelete(head, n, m);

    cout << "Modified List after deleting " << n
         << " nodes after every " << m << " nodes: ";
    printList(head);

    return 0;
}
