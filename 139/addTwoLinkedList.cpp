// Leetcode - 2. Add Two Numbers

#include <bits/stdc++.h>
using namespace std;

// Linked list node structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse both lists first
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;

        while (l1 != NULL && l2 != NULL) {
            int sum = carry + l1->val + l2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            if (ansHead == NULL) {
                ansHead = newNode;
                ansTail = newNode;
            } else {
                ansTail->next = newNode;
                ansTail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            int sum = carry + l1->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l1 = l1->next;
        }

        while (l2 != NULL) {
            int sum = carry + l2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l2 = l2->next;
        }

        while (carry != 0) {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }

        // Reverse the result before returning
        ansHead = reverseList(ansHead);

        return ansHead;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Helper function to create a linked list from a vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    // Example: 7243 + 564 = 7807
    ListNode* l1 = createList({7, 2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
