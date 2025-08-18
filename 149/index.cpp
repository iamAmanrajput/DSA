// LeetCode : 2181. Merge Nodes in Between Zeros

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *slow = head;       // slow pointer will mark new node positions (where sum will be stored)
        ListNode *fast = head->next; // fast pointer used to traverse
        ListNode *newLastNode = nullptr;
        int sum = 0;

        while (fast)
        {
            if (fast->val != 0)
            {
                // Keep adding values until we encounter 0
                sum += fast->val;
            }
            else
            {
                // When we encounter 0, put the sum at slow node
                slow->val = sum;
                newLastNode = slow; // keep track of last updated node
                slow = slow->next;  // move slow forward
                sum = 0;            // reset sum
            }
            fast = fast->next; // keep traversing
        }

        // Disconnect extra nodes after last merged node
        ListNode *temp = newLastNode->next;
        newLastNode->next = nullptr;

        // Delete the remaining unused nodes to prevent memory leak
        while (temp)
        {
            ListNode *nxt = temp->next;
            delete temp;
            temp = nxt;
        }

        return head;
    }
};

// Utility function to create linked list from vector
ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (int i = 1; i < vals.size(); i++)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main()
{
    // Example: Input list: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    vector<int> vals = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode *head = createList(vals);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode *merged = sol.mergeNodes(head);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
