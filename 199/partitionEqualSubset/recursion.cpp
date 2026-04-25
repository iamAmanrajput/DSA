// Leetcode problem 416. Partition Equal Subset Sum
// Time Complexity (TC): O(2^n)
// Space Complexity (SC): O(n)
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    // Recursive helper to check if a subset sum equals the target
    bool check(vector<int> &nums, int i, int target)
    {
        // Base Case: Target achieved
        if (target == 0)
        {
            return true;
        }
        // Base Case: Out of bounds or target becomes negative
        if (i >= nums.size() || target < 0)
        {
            return false;
        }

        // Recursive Step: Include current element or exclude it
        bool include = check(nums, i + 1, target - nums[i]);
        bool exclude = check(nums, i + 1, target);

        return include || exclude;
    }

    bool canPartition(vector<int> &nums)
    {
        int index = 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        };

        // If the total sum is odd, we cannot split it into two equal integer subsets
        if (totalSum & 1)
        {
            return false;
        }

        int target = totalSum / 2;
        return check(nums, index, target);
    }
};

int main()
{
    Solution sol;

    // Test Case 1: Possible to partition [1, 5, 11, 5] -> [1, 5, 5] and [11]
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test Case 1: " << (sol.canPartition(nums1) ? "True" : "False") << endl;

    // Test Case 2: Impossible to partition [1, 2, 3, 5]
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test Case 2: " << (sol.canPartition(nums2) ? "True" : "False") << endl;

    return 0;
}