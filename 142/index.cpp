// LeetCode : 21. Merge Two Sorted Lists
// Iterative Approach

#include <iostream>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2)
        {
            return list2;
        }
        if (list2 == NULL && list1)
        {
            return list1;
        }

        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                if (ansHead == NULL)
                {
                    ansHead = list1;
                    ansTail = list1;
                    list1 = list1->next;
                    ansHead->next = NULL;
                }
                else
                {
                    ansTail->next = list1;
                    ansTail = ansTail->next;
                    list1 = list1->next;
                    ansTail->next = NULL;
                }
            }
            else
            {
                if (ansHead == NULL)
                {
                    ansHead = list2;
                    ansTail = list2;
                    list2 = list2->next;
                    ansHead->next = NULL;
                }
                else
                {
                    ansTail->next = list2;
                    ansTail = ansTail->next;
                    list2 = list2->next;
                    ansTail->next = NULL;
                }
            }
        }

        while (list1 != NULL)
        {
            ansTail->next = list1;
            ansTail = ansTail->next;
            list1 = list1->next;
            ansTail->next = NULL;
        }

        while (list2 != NULL)
        {
            ansTail->next = list2;
            ansTail = ansTail->next;
            list2 = list2->next;
            ansTail->next = NULL;
        }

        return ansHead;
    }
};

// Helper function to create a linked list from an array
ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;
    for (int i = 1; i < n; i++)
    {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    ListNode *list1 = createList(arr1, 3);
    ListNode *list2 = createList(arr2, 3);

    Solution s;
    ListNode *mergedList = s.mergeTwoLists(list1, list2);

    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}
