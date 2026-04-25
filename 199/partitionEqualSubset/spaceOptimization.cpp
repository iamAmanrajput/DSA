// Leetcode problem 416. Partition Equal Subset Sum
/**
 * TC: O(n * target) - Still iterating through all elements and sum range.
 * SC: O(target)     - Reduced space from O(n * target) to two rows of size target.
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

        // Odd sum cannot be split into two equal integer subsets
        if (totalSum & 1)
        {
            return false;
        }

        int target = totalSum / 2;
        int n = nums.size();

        // Space Optimization: We only need the 'next' row to calculate the 'curr' row
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        // Base Case: If the current sum 's' has reached 'target', it's true (1)
        curr[target] = 1;
        next[target] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            // We start from target-1 because target is already set as the base case
            for (int s = target - 1; s >= 0; s--)
            {
                bool include = 0;
                if (s + nums[idx] <= target)
                {
                    include = next[s + nums[idx]];
                }

                bool exclude = next[s];

                curr[s] = (include || exclude);
            }
            // Move current results to 'next' for the next element iteration
            next = curr;
        }

        // The answer is stored in the first index of the finalized 'next' row
        return next[0];
    }
};

int main()
{
    Solution sol;

    // Test Case 1: Expected output: True ({1, 5, 5} and {11})
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test Case 1: " << (sol.canPartition(nums1) ? "True" : "False") << endl;

    // Test Case 2: Expected output: False
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test Case 2: " << (sol.canPartition(nums2) ? "True" : "False") << endl;

    // Test Case 3: Edge Case (Empty or Single element)
    vector<int> nums3 = {10};
    cout << "Test Case 3: " << (sol.canPartition(nums3) ? "True" : "False") << endl;

    return 0;
}