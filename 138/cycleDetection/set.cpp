// 141. Linked List Cycle -- (LC)
// # using Set Approach

#include <iostream>
#include <unordered_set>
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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited;

        ListNode *curr = head;
        while (curr != NULL)
        {
            if (visited.find(curr) != visited.end())
            {
                return true; // cycle hai
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false; // cycle nahi hai
    }
};

int main()
{
    // Example Linked List: 1->2->3->4->NULL (no cycle)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution obj;
    if (obj.hasCycle(head))
    {
        cout << "Cycle hai" << endl;
    }
    else
    {
        cout << "Cycle nahi hai" << endl;
    }

    // Clean up memory
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
