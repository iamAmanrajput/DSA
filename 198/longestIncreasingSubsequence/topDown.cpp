// Leetcode Problem 300. Longest Increasing Subsequence
/*
    Time Complexity:
    O(n * n)
    Each state (curr, prev) is computed once

    Space Complexity:
    O(n * n) for dp table
    O(n) recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Longest Increasing Subsequence (LIS)

    Given an integer array nums,
    return the length of the longest strictly increasing subsequence.

    Approach: Recursion + Memoization (Top-Down DP)

    Idea:
    At every index (curr), we have two choices:
    1. Include current element (if it maintains increasing order)
    2. Exclude current element

    Parameters:
    curr → current index we are processing
    prev → index of previously included element (-1 means none selected yet)

    dp[curr][prev + 1] is used for memoization:
    - prev can be -1, so we shift index by +1 to avoid negative indexing
*/

class Solution
{
public:
    int solve(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {

        // Base Case: if we reach end of array
        if (curr >= nums.size())
        {
            return 0;
        }

        // Return already computed result
        // we shift prev + 1 bcz -1 index is not exists
        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }

        int include = 0;

        /*
            Include current element only if:
            - no previous element selected (prev == -1)
            - OR current element is greater than previous element
        */
        if (prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + solve(nums, curr + 1, curr, dp);
        }

        // Exclude current element
        int exclude = 0 + solve(nums, curr + 1, prev, dp);

        // Store result in dp and return
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    int lengthOfLIS(vector<int> &nums)
    {

        int curr = 0;
        int prev = -1;

        /*
            dp size:
            rows → curr (0 to n)
            cols → prev + 1 (to handle -1 case)
        */
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, -1));

        int ans = solve(nums, curr, prev, dp);
        return ans;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << obj.lengthOfLIS(nums1) << endl;
    // Expected Output: 4

    // Test Case 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "LIS Length: " << obj.lengthOfLIS(nums2) << endl;
    // Expected Output: 4

    // Test Case 3
    vector<int> nums3 = {7, 7, 7, 7, 7};
    cout << "LIS Length: " << obj.lengthOfLIS(nums3) << endl;
    // Expected Output: 1

    return 0;
}