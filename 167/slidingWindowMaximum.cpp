// Leetcode 239. Sliding Window Maximum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;   // will store indices of useful elements
        vector<int> ans; // to store answers

        // Process first window of size k
        for (int i = 0; i < k; i++)
        {
            // Remove smaller elements from back
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // Insert current index
            dq.push_back(i);
        }

        // Store answer for first window
        ans.push_back(nums[dq.front()]);

        // Process remaining windows
        for (int i = k; i < nums.size(); i++)
        {

            // Remove elements which are out of the current window
            if (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            // Remove smaller elements for current element
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            // Insert current index
            dq.push_back(i);

            // Store maximum of current window
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Test case
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    // Print result
    cout << "Sliding Window Maximums: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}


// Sliding Window Maximums: 3 3 5 5 6 7
