// Leetcode : 138. Copy List with Random Pointer
// TC O(n)
// SC O(1)
// without map

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Definition for a Node.
// ---------------------------
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

// ---------------------------
// Solution Class
// ---------------------------
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return 0; // If the list is empty, return null

        // --------------------
        // Step 1: Clone nodes and insert them between original nodes
        // Example: A -> B -> C  becomes  A -> A' -> B -> B' -> C -> C'
        // --------------------
        Node *it = head; // Iterator to traverse the original list
        while (it)
        {
            Node *clonedNode = new Node(it->val); // Create a clone of the current node
            clonedNode->next = it->next;          // Link clone's next to original's next
            it->next = clonedNode;                // Insert clone right after original node
            it = it->next->next;                  // Move to the next original node
        }

        // --------------------
        // Step 2: Assign random pointers for cloned nodes
        // Each clone's random = original's random's next (which is the cloned node of that random)
        // --------------------
        it = head;
        while (it)
        {
            Node *clonedNode = it->next; // Get the cloned node
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next; // Move to the next original node
        }

        // --------------------
        // Step 3: Detach the cloned list from the original list
        // Restore original list and build separate cloned list
        // --------------------
        it = head;
        Node *clonedHead = it->next; // Head of the cloned list

        while (it)
        {
            Node *clonedNode = it->next; // Clone node of current original
            it->next = it->next->next;   // Restore original's next pointer
            if (clonedNode->next)
            {                                              // If next clone exists
                clonedNode->next = clonedNode->next->next; // Link to next clone
            }
            it = it->next; // Move to next original node
        }

        // Return the head of the cloned linked list
        return clonedHead;
    }
};

// ---------------------------
// Helper function to print list
// ---------------------------
void printList(Node *head)
{
    while (head)
    {
        cout << "Node val: " << head->val;
        if (head->random)
            cout << ", Random val: " << head->random->val;
        else
            cout << ", Random val: NULL";
        cout << "\n";
        head = head->next;
    }
}

// ---------------------------
// Main function
// ---------------------------
int main()
{
    // Creating example list: 1 -> 2 -> 3
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    // Assign random pointers
    n1->random = n3; // 1's random -> 3
    n2->random = n1; // 2's random -> 1
    n3->random = n2; // 3's random -> 2

    cout << "Original List:\n";
    printList(n1);

    // Clone using Solution class
    Solution sol;
    Node *clonedHead = sol.copyRandomList(n1);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}
