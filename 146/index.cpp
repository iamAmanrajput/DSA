// LeetCode : 61. Rotate List

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list node.
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
    // Function to calculate length of linked list
    int getLength(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            head = head->next;
            count++;
        }
        return count;
    }

    // Function to rotate linked list to the right by k positions
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
        {
            return nullptr; // Empty list
        }

        int length = getLength(head);

        // Effective rotations (agar k > length ho)
        int actualRotateK = k % length;

        // Agar rotation ka effect hi na ho
        if (actualRotateK == 0)
        {
            return head;
        }

        // Naya last node ka position (0-based index)
        int newLastNodePosition = length - actualRotateK - 1;

        // Traverse karke new last node dhoondo
        ListNode *newLastNode = head;
        for (int i = 0; i < newLastNodePosition; i++)
        {
            newLastNode = newLastNode->next;
        }

        // New head = next of newLastNode
        ListNode *newHead = newLastNode->next;
        newLastNode->next = NULL; // Break link

        // Traverse till end of list to connect with old head
        ListNode *it = newHead;
        while (it->next)
        {
            it = it->next;
        }
        it->next = head;

        return newHead;
    }
};

// Helper function to print linked list
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

int main()
{
    // Example: Create a linked list 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    int k = 2; // Rotate by 2
    ListNode *rotatedHead = sol.rotateRight(head, k);

    cout << "Rotated List (by " << k << "): ";
    printList(rotatedHead);

    return 0;
}
