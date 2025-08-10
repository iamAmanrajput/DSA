// 141. Linked List Cycle II -- (LC)
// # using Floyd’s Cycle Detection (Tortoise and Hare)

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false; // Empty or single node -> no cycle

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;       // Move 1 step
            fast = fast->next->next; // Move 2 steps

            if (slow == fast)
                return true; // Cycle detected
        }

        return false; // fast reached NULL => no cycle
    }
};

// Example usage
int main()
{
    // Create nodes
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    // Link nodes: 3 -> 2 -> 0 -> -4 -> 2 (cycle)
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // cycle here

    Solution obj;
    if (obj.hasCycle(head))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
