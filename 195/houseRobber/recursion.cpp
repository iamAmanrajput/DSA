// Leetcode Problem 198. House Robber
// Time Complexity: O(2^n) (exponential)
// Space Complexity: O(n) (recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Pure recursive function (no memoization)
    int solve(vector<int> &nums, int index)
    {

        // Base Case:
        // If index goes out of bounds, no money can be robbed
        if (index >= nums.size())
        {
            return 0;
        }

        // Choice 1: Include current house
        // Rob current house and move to index + 2
        int include = nums[index] + solve(nums, index + 2);

        // Choice 2: Exclude current house
        // Skip current house and move to index + 1
        int exclude = 0 + solve(nums, index + 1);

        // Return maximum of both choices
        return max(include, exclude);
    }

    int rob(vector<int> &nums)
    {
        return solve(nums, 0); // Start from index 0
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

    // Test Case 3
    vector<int> nums3 = {5};
    cout << "Maximum money that can be robbed: "
         << obj.rob(nums3) << endl; // Expected: 5

    return 0;
}