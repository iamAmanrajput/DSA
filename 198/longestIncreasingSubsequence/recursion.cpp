// Leetcode Problem 300. Longest Increasing Subsequence
/*
    Time Complexity:
    O(2^n)  (each element has include/exclude choice → exponential)

    Space Complexity:
    O(n) recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Longest Increasing Subsequence (LIS)

    Given an integer array nums,
    return the length of the longest strictly increasing subsequence.

    Approach: Recursion (Include / Exclude)

    Idea:
    At every index (curr), we have 2 choices:
    1. Include current element (if valid increasing condition satisfied)
    2. Exclude current element

    prev → stores index of last included element
    curr → current index we are exploring

    Base Case:
    If curr >= nums.size() → no elements left → return 0
*/

class Solution
{
public:
    int solve(vector<int> &nums, int curr, int prev)
    {

        // Base Case: no elements left
        if (curr >= nums.size())
        {
            return 0;
        }

        int include = 0;

        /*
            Include current element only if:
            - no previous element chosen (prev == -1)
            - OR current element is greater than previous element
        */
        if (prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + solve(nums, curr + 1, curr);
        }

        // Exclude current element
        int exclude = 0 + solve(nums, curr + 1, prev);

        // Take maximum of include and exclude
        return max(include, exclude);
    }

    int lengthOfLIS(vector<int> &nums)
    {

        int curr = 0;
        int prev = -1;

        // Start recursion
        int ans = solve(nums, curr, prev);
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
    // LIS example: {2, 3, 7, 101}

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