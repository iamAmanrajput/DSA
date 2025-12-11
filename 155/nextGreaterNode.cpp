// Leetcode Problem 1019. Next Greater Node In Linked List

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {

        // Convert linked list to array for easier access
        vector<int> ll;
        while (head)
        {
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st;              // will store indices of elements
        vector<int> ans(ll.size()); // default = 0 for all elements

        // Iterate through array
        for (int i = 0; i < ll.size(); i++)
        {

            // If current value > previous stored index value -> update answer
            while (!st.empty() && ll[i] > ll[st.top()])
            {
                int kids = st.top(); // index which has found its next greater
                st.pop();
                ans[kids] = ll[i]; // assign next greater element
            }

            st.push(i); // push current index
        }

        // Remaining indices (in stack) have no next greater value → remain 0
        return ans;
    }
};

int main()
{
    // -------------------------------
    // TEST CASE: Linked list = [2, 1, 5]
    // Expected output: [5, 5, 0]
    // -------------------------------

    // Create linked list: 2 -> 1 -> 5
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    Solution sol;
    vector<int> result = sol.nextLargerNodes(head);

    // Print result
    cout << "Next greater nodes: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
