// GFG - Sort a linked list of 0s, 1s and 2s
// without updating data

#include <bits/stdc++.h>
using namespace std;

/* Linked list node structure */
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *segregate(Node *head)
    {
        // If list is empty or has only one node, return as it is
        if (!head || !head->next)
            return head;

        // Dummy heads banate hai 0's, 1's aur 2's ke liye
        // In dummy nodes ka kaam sirf starting point dena hai
        Node *Zero = new Node(-1);
        Node *zeroTail = Zero; // 0's list ka tail

        Node *One = new Node(-1);
        Node *oneTail = One; // 1's list ka tail

        Node *Two = new Node(-1);
        Node *twoTail = Two; // 2's list ka tail

        // Original list traverse karke data ke hisaab se nodes ko alag-alag list me daalna
        Node *curr = head;
        while (curr)
        {
            if (curr->data == 0)
            {
                // Agar node ka data 0 hai → 0's list me lagao
                zeroTail->next = curr;
                zeroTail = zeroTail->next; // Tail ko aage badhao
            }
            else if (curr->data == 1)
            {
                // Agar node ka data 1 hai → 1's list me lagao
                oneTail->next = curr;
                oneTail = oneTail->next;
            }
            else
            {
                // Agar node ka data 2 hai → 2's list me lagao
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            // Move to next node in original list
            curr = curr->next;
        }

        // Ab teen alag-alag lists ko connect karna hai

        // 0's list ka tail → agar 1's list present hai to uske head par,
        // warna direct 2's list ke head par
        zeroTail->next = (One->next) ? One->next : Two->next;

        // Agar 1's list empty nahi hai, to 1's tail ko 2's list ke head se connect karo
        if (One->next)
        {
            oneTail->next = Two->next;
        }

        // 2's tail ka next NULL kar do (list ka proper end)
        twoTail->next = NULL;

        // Nayi sorted list ka head = Zero dummy node ke next se start hoga
        Node *newHead = Zero->next;

        // Dummy nodes ko delete kar do (memory leak na ho)
        delete Zero;
        delete One;
        delete Two;

        // Sorted linked list ka head return karo
        return newHead;
    }
};

// Helper functions for testing
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    // Example: 2 -> 1 -> 0 -> 2 -> 1 -> 0
    Node *head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(0);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.segregate(head);

    cout << "Sorted list:   ";
    printList(head);

    return 0;
}
