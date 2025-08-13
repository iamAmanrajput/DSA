// 160. Intersection of Two Linked Lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
        {
            return NULL;
        }

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        while (temp1 && temp2)
        {
            if (temp1 == temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        ListNode *getBigger = temp1 == NULL ? headB : headA;
        int biggerLength = 0;

        while (temp1)
        {
            temp1 = temp1->next;
            biggerLength++;
        }
        while (temp2)
        {
            temp2 = temp2->next;
            biggerLength++;
        }

        if (headA == getBigger)
        {
            while (biggerLength != 0)
            {
                headA = headA->next;
                biggerLength--;
            }
        }
        else
        {
            while (biggerLength != 0)
            {
                headB = headB->next;
                biggerLength--;
            }
        }

        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};

int main()
{
    // Creating first linked list: 1 -> 2 -> 3 \
    //                                           -> 6 -> 7
    // Creating second linked list:       4 -> 5 /
    ListNode *common = new ListNode(6);
    common->next = new ListNode(7);

    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    ListNode *headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common;

    Solution s;
    ListNode *intersection = s.getIntersectionNode(headA, headB);

    if (intersection)
    {
        cout << "Intersection Node value: " << intersection->val << endl;
    }
    else
    {
        cout << "No Intersection" << endl;
    }

    return 0;
}

// Intersection Node value: 6
