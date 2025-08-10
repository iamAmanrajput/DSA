// 142. Linked List Cycle II

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect cycle using Floyd's algorithm
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // Step 2: Find starting point of cycle
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Cycle ka starting node
            }
        }

        return NULL;
    }
};

int main()
{
    // Linked list nodes create karna
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Cycle create karna: last node ko 2nd node se jodna
    head->next->next->next->next = head->next;

    Solution sol;
    ListNode *cycleStart = sol.detectCycle(head);

    if (cycleStart)
    {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    }
    else
    {
        cout << "No cycle found" << endl;
    }

    // ⚠ Note: Memory leak free karna skip kiya hai kyunki cycle hai
    return 0;
}
