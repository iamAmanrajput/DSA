// Leetcode problem 416. Partition Equal Subset Sum
/**
 * TC: O(n * target) - Nested loops run for 'n' elements and 'target' sum.
 * SC: O(n * target) - 2D DP table of size (n+2) x (target+1).
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        // Odd check: Equal partition is impossible if total sum is odd
        if (totalSum & 1)
        {
            return false;
        }

        int target = totalSum / 2;
        int n = nums.size();

        // DP table initialization
        // dp[idx][s] represents if it's possible to reach 'target' starting
        // from 'idx' with current sum 's'
        vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));

        // Base Case: If current sum 's' is already 'target', it's true
        for (int row = 0; row <= n; row++)
        {
            dp[row][target] = 1;
        }

        // Iterative Bottom-Up approach
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int s = target - 1; s >= 0; s--)
            { // Start from target-1 because target is base case
                bool include = 0;
                // Check if including the current number stays within target bounds
                if (s + nums[idx] <= target)
                {
                    include = dp[idx + 1][s + nums[idx]];
                }

                // Check excluding the current number
                bool exclude = dp[idx + 1][s];

                dp[idx][s] = (include || exclude);
            }
        }

        // Result: Starting from index 0 with 0 sum, can we reach target?
        return dp[0][0];
    }
};

int main()
{
    Solution sol;

    // Test Case 1: Expected output: True (Subsets {1, 5, 5} and {11})
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test Case 1: " << (sol.canPartition(nums1) ? "True" : "False") << endl;

    // Test Case 2: Expected output: False
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test Case 2: " << (sol.canPartition(nums2) ? "True" : "False") << endl;

    // Test Case 3: Expected output: True (Subsets {1, 2} and {3})
    vector<int> nums3 = {1, 2, 3};
    cout << "Test Case 3: " << (sol.canPartition(nums3) ? "True" : "False") << endl;

    return 0;
}