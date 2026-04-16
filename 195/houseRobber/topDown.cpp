// Leetcode Problem 198. House Robber
// Time Complexity: O(n)
// Space Complexity: O(n) + recursion stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function with memoization (Top-Down DP)
    int solve(vector<int> &nums, int index, vector<int> &dp)
    {

        // Base Case:
        // If index goes out of bounds, no money can be robbed
        if (index >= nums.size())
        {
            return 0;
        }

        // Step 1: Check if result already computed
        if (dp[index] != -1)
        {
            return dp[index];
        }

        // Step 2: Include current house
        // Rob current house and move to index + 2
        int include = nums[index] + solve(nums, index + 2, dp);

        // Step 3: Exclude current house
        // Skip current house and move to index + 1
        int exclude = 0 + solve(nums, index + 1, dp);

        // Step 4: Store the maximum of both choices
        dp[index] = max(include, exclude);

        return dp[index];
    }

    int rob(vector<int> &nums)
    {

        // DP array initialized with -1 (means not computed)
        vector<int> dp(nums.size() + 1, -1);

        int index = 0;

        // Start recursion from index 0
        return solve(nums, index, dp);
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Maximum money that can be robbed: "
         << obj.rob(nums1) << endl; // Expected: 4

    // Test Case 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Maximum money that can be robbed: "
         << obj.rob(nums2) << endl; // Expected: 12

    // Test Case 3 (edge case)
    vector<int> nums3 = {5};
    cout << "Maximum money that can be robbed: "
         << obj.rob(nums3) << endl; // Expected: 5

    return 0;
}