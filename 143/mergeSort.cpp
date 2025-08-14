// 148. Sort List --(LC)
// Using Merge Sort

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

class Solution
{
public:
    // Function to find the middle node of the linked list
    // This is used to split the list into two halves
    ListNode *findMid(ListNode *&head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        // Move 'fast' by 2 steps and 'slow' by 1 step
        // When 'fast' reaches end, 'slow' will be at mid
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow; // Midpoint
    }

    // Function to merge two sorted linked lists into one sorted list
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        // If one of the lists is empty, return the other
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *ansHead = nullptr; // Head of the merged list
        ListNode *ansTail = nullptr; // Tail pointer for building the list

        // Merge both lists node by node
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                // If ansHead is empty, initialize it
                if (!ansHead)
                {
                    ansHead = ansTail = list1;
                }
                else
                {
                    ansTail->next = list1;
                    ansTail = ansTail->next;
                }
                list1 = list1->next; // Move forward in list1
            }
            else
            {
                if (!ansHead)
                {
                    ansHead = ansTail = list2;
                }
                else
                {
                    ansTail->next = list2;
                    ansTail = ansTail->next;
                }
                list2 = list2->next; // Move forward in list2
            }
            ansTail->next = nullptr; // Break old links
        }

        // Attach any remaining nodes
        if (list1)
            ansTail->next = list1;
        if (list2)
            ansTail->next = list2;

        return ansHead; // Return merged sorted list
    }

    // Main function to sort the linked list using merge sort
    ListNode *sortList(ListNode *head)
    {
        // Base case: if list has 0 or 1 node, it's already sorted
        if (!head || !head->next)
            return head;

        // Step 1: Find middle node
        ListNode *mid = findMid(head);

        // Step 2: Split into two lists
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr; // Break the link

        // Step 3: Recursively sort each half
        left = sortList(left);
        right = sortList(right);

        // Step 4: Merge the two sorted halves
        return merge(left, right);
    }
};

// Helper function to print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
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

int main()
{
    // Input vector representing the linked list
    vector<int> vals = {4, 2, 1, 3};

    // Create linked list from vector
    ListNode *head = createList(vals);

    cout << "Original List: ";
    printList(head);

    // Create Solution object and sort the list
    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}
