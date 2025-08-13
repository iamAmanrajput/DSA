// Get Node Value -- (HACKER RANK)
// Recursive Approach

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Recursive helper function
void helper(Node *head, int &posFromTail, int &ans)
{
    if (head == NULL)
        return;
    helper(head->next, posFromTail, ans);
    if (posFromTail == 0)
        ans = head->data;
    posFromTail--;
}

// Function to get node value from tail
int getNode(Node *head, int positionFromTail)
{
    int ans = -1;
    helper(head, positionFromTail, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n; // number of nodes
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Node *newNode = new Node(val);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pos;
    cin >> pos;

    cout << getNode(head, pos) << endl;
    return 0;
}
