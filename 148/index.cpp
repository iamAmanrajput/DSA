// LeetCode : 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        // Answer format: {minDist, maxDist}, initialized to {-1,-1} as default
        vector<int> ans = {-1, -1};

        // Pointers for traversal
        ListNode *prev = head;
        if (!prev)
            return ans;

        ListNode *curr = head->next; // We need at least 3 nodes to check critical point
        if (!curr)
            return ans;

        ListNode *nxt = head->next->next;
        if (!nxt)
            return ans;

        // Store first critical point index and last critical point index
        int firstCP = -1;
        int lastCP = -1;

        // Initialize minDist with a large value
        int minDist = INT_MAX;

        // Start index = 1 (because 'curr' is second node in the list)
        int i = 1;

        // Traverse till we have next node
        while (nxt)
        {
            // Check if 'curr' is a critical point
            // Condition for local maxima OR local minima
            bool isCP =
                ((curr->val > prev->val && curr->val > nxt->val) || // Local maxima
                 (curr->val < prev->val && curr->val < nxt->val));  // Local minima

            if (isCP && firstCP == -1)
            {
                // First critical point found
                firstCP = i;
                lastCP = i;
            }
            else if (isCP)
            {
                // Another critical point found
                // Update minimum distance between consecutive critical points
                minDist = min(minDist, i - lastCP);
                // Update last critical point
                lastCP = i;
            }

            // Move pointers forward
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }

        // If only one CP is found, return {-1, -1}
        if (lastCP == firstCP)
        {
            return ans;
        }
        else
        {
            // Minimum distance and maximum distance
            ans[0] = minDist;
            ans[1] = lastCP - firstCP;
        }

        return ans;
    }
};

// Helper function to create linked list from vector
ListNode *createList(vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *temp = head;
    for (int i = 1; i < vals.size(); i++)
    {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to free memory
void freeList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    // Example input
    vector<int> vals = {5, 3, 1, 2, 5, 1, 2};
    // Linked list: 5 -> 3 -> 1 -> 2 -> 5 -> 1 -> 2

    ListNode *head = createList(vals);

    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);

    cout << "Minimum Distance: " << result[0] << endl;
    cout << "Maximum Distance: " << result[1] << endl;

    // Free memory
    freeList(head);

    return 0;
}
