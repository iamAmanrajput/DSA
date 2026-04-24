// Leetcode Problem 300. Longest Increasing Subsequence
/*
    Time Complexity:
    O(n * n)

    Space Complexity:
    O(n)
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Longest Increasing Subsequence (LIS)

    Given an integer array nums,
    return the length of the longest strictly increasing subsequence.

    Approach: Space Optimized DP

    Idea:
    We convert 2D DP into 1D using two arrays:
    - currRow → dp[i][*]
    - nextRow → dp[i+1][*]

    j represents previous index (shifted by +1)
    because prev can be -1

    Shifting:
        prev = -1 → index 0
        prev = 0  → index 1
        prev = 1  → index 2
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();

        // currRow → current row (dp[i][...])
        // nextRow → next row (dp[i+1][...])
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        /*
            Fill DP from bottom (reverse order)
            because current state depends on next row
        */
        for (int i = n - 1; i >= 0; i--)
        {

            /*
                j represents previous index (shifted)
                actual prev = j - 1
            */
            for (int j = i - 1; j >= -1; j--)
            {

                int include = 0;

                /*
                    Include current element if:
                    - no previous element (j == -1)
                    - OR nums[j] < nums[i]
                */
                if (j == -1 || nums[j] < nums[i])
                {

                    /*
                        include = 1 + dp[i+1][i]

                        shifted index:
                        prev = i → i+1
                    */
                    include = 1 + nextRow[i + 1];
                }

                /*
                    Exclude current element:
                    prev remains same

                    shifted index:
                    j → j+1
                */
                int exclude = 0 + nextRow[j + 1];

                /*
                    Store result:
                    j+1 used because prev can be -1
                */
                currRow[j + 1] = max(include, exclude);
            }

            // Move current row to next row
            nextRow = currRow;
        }

        /*
            Final answer:
            curr = 0, prev = -1 → index 0
        */
        return nextRow[0];
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