// Leetcode Problem 300. Longest Increasing Subsequence
// Time Complexity (TC)
// O(n log n)
// Space Complexity (SC)
// O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ans;

        // Step 1: first element ko push kar do (initial state)
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {

            // Agar current element bada hai last element se
            // to LIS extend ho jayega
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // warna replace karna padega
                // lower_bound: first element >= nums[i]
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

                // replace to maintain smallest possible tail
                ans[index] = nums[i];
            }
        }

        return ans.size(); // LIS length
    }
};

int main()
{
    Solution obj;

    // Test Case
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int result = obj.lengthOfLIS(nums);

    cout << "Length of LIS: " << result << endl;

    return 0;
}