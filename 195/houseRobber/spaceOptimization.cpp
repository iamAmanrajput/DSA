// Leetcode Problem 198. House Robber
// Time Complexity = O(n)
// Space Complexity: O(1)
// Tabulation + Space Optimization

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        // Edge case: if array is empty
        if (n == 0)
            return 0;

        // Edge case: if only one house
        if (n == 1)
            return nums[0];

        // prev → dp[index + 1]
        // next → dp[index + 2]
        int prev = nums[n - 1]; // last house
        int next = 0;           // beyond last (0)
        int curr = 0;

        // Traverse from right to left
        for (int index = n - 2; index >= 0; index--)
        {

            // Include current house
            int include = nums[index] + next;

            // Exclude current house
            int exclude = prev;

            // Take maximum
            curr = max(include, exclude);

            // Shift values for next iteration
            next = prev;
            prev = curr;
        }

        // Final answer stored in curr
        return curr;
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Output: " << obj.rob(nums1) << endl; // Expected: 4

    // Test Case 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Output: " << obj.rob(nums2) << endl; // Expected: 12

    // Test Case 3 (single element)
    vector<int> nums3 = {5};
    cout << "Output: " << obj.rob(nums3) << endl; // Expected: 5

    // Test Case 4 (empty array)
    vector<int> nums4 = {};
    cout << "Output: " << obj.rob(nums4) << endl; // Expected: 0

    return 0;
}