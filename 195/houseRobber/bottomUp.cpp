// Leetcode Problem 198. House Robber
// Time Complexity = O(n)
// Space Complexity: O(n)

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

        // step 1: create dp array
        vector<int> dp(n, -1);

        // step 2: base case
        dp[n - 1] = nums[n - 1];

        // step 3: fill dp array from right to left
        for (int index = n - 2; index >= 0; index--)
        {

            int tempAns = 0;

            // safe check for index + 2
            if (index + 2 < n)
            {
                tempAns = dp[index + 2];
            }

            // include current house
            int include = nums[index] + tempAns;

            // exclude current house
            int exclude = dp[index + 1];

            // store maximum
            dp[index] = max(include, exclude);
        }

        // final answer
        return dp[0];
    }
};

int main()
{

    Solution obj;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << obj.rob(nums1) << endl; // Expected: 4

    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << obj.rob(nums2) << endl; // Expected: 12

    vector<int> nums3 = {};
    cout << obj.rob(nums3) << endl; // Expected: 0

    return 0;
}