// Leetcode Problem 23. Merge k Sorted Lists

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Comparator for min heap
// Smallest node (based on val) will be on top
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // min heap
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        // Min heap to store nodes
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

        int k = lists.size();

        // Edge case: no lists
        if (k == 0)
        {
            return NULL;
        }

        // Step 1: push first node of each list into heap
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        // Step 2: process heap
        while (!minHeap.empty())
        {
            ListNode *top = minHeap.top();
            minHeap.pop();

            // Push next node of same list (if exists)
            if (top->next)
            {
                minHeap.push(top->next);
            }

            // Build the result linked list
            if (head == NULL)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};

// Helper function to print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Solution obj;

    // Create test linked lists:
    // List 1: 1 -> 4 -> 7
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(7)));

    // List 2: 2 -> 5 -> 8
    ListNode *l2 = new ListNode(2, new ListNode(5, new ListNode(8)));

    // List 3: 3 -> 6 -> 9
    ListNode *l3 = new ListNode(3, new ListNode(6, new ListNode(9)));

    vector<ListNode *> lists = {l1, l2, l3};

    // Merge k sorted linked lists
    ListNode *result = obj.mergeKLists(lists);

    // Print result
    cout << "Merged Linked List: ";
    printList(result);

    return 0;
}

// Merged Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL