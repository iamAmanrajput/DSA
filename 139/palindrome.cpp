// 234. Palindrome Linked List
// #Approach 2

#include <iostream>
using namespace std;

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
    // Iterative reverse function
    ListNode *reverseNode(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        if (head->next == NULL)
        {
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Find middle node using slow-fast pointer
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half starting from slow
        ListNode *secondHalf = reverseNode(slow);

        // Compare first half and reversed second half
        ListNode *firstHalf = head;
        ListNode *tempSecond = secondHalf;

        while (tempSecond != NULL)
        {
            if (firstHalf->val != tempSecond->val)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            tempSecond = tempSecond->next;
        }

        return true;
    }
};

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

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode *n5 = new ListNode(1);
    ListNode *n4 = new ListNode(2, n5);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    Solution sol;
    cout << "Linked List: ";
    printList(n1);

    if (sol.isPalindrome(n1))
    {
        cout << "The linked list is a palindrome.\n";
    }
    else
    {
        cout << "The linked list is NOT a palindrome.\n";
    }

    // Clean up memory (optional)
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}
