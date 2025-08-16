// Leetcode : 138. Copy List with Random Pointer
// TC O(n)
// SC O(n)

#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Node structure with value, next pointer, and random pointer
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    // Recursive helper function to clone the list
    Node *helper(Node *head, unordered_map<Node *, Node *> &mp)
    {
        // Base case: If current node is NULL, return NULL
        if (head == 0)
            return 0;

        // Create a new node (deep copy of current node)
        Node *newHead = new Node(head->val);

        // Map original node to its copy
        mp[head] = newHead;

        // Recursively copy the 'next' node
        newHead->next = helper(head->next, mp);

        // If random pointer exists, connect it using the map
        if (head->random)
        {
            newHead->random = mp[head->random];
        }

        // Return the copied head
        return newHead;
    }

    // Main function to copy a linked list with random pointer
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp; // old node --> new node mapping
        return helper(head, mp);
    }
};

// Function to print the list for verification
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << "Node value: " << temp->val;
        if (temp->random)
            cout << ", Random points to: " << temp->random->val;
        else
            cout << ", Random points to: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    // Creating a sample list: 1 -> 2 -> 3
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Assign random pointers
    head->random = head->next->next;       // 1's random -> 3
    head->next->random = head;             // 2's random -> 1
    head->next->next->random = head->next; // 3's random -> 2

    cout << "Original list:\n";
    printList(head);

    Solution sol;
    Node *copiedList = sol.copyRandomList(head);

    cout << "\nCopied list:\n";
    printList(copiedList);

    return 0;
}
