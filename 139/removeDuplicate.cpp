// Leetcode - 83. Remove Duplicates from Sorted List

#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        while (temp != NULL)
        {
            if ((temp->next != NULL) && (temp->val == temp->next->val))
            {
                ListNode *forward = temp->next;
                temp->next = temp->next->next;
                forward->next = NULL;
                delete forward; // free memory of removed duplicate
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Helper function to create linked list from array
ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Helper function to free memory
void deleteList(ListNode *head)
{
    while (head != NULL)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int arr[] = {1, 1, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createList(arr, n);
    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    deleteList(head); // clean up memory
    return 0;
}

// Original List: 1 -> 1 -> 1 -> 2 -> 3 -> 3 -> NULL
// After Removing Duplicates: 1 -> 2 -> 3 -> NULL
