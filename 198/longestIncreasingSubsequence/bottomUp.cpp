// Leetcode Problem 300. Longest Increasing Subsequence
/*
    Time Complexity:
    O(n * n)

    Space Complexity:
    O(n * n)
*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Longest Increasing Subsequence (LIS)

    Given an integer array nums,
    return the length of the longest strictly increasing subsequence.

    Approach: Tabulation (Bottom-Up DP)

    Idea:
    dp[i][j] represents the answer for:
    curr index = i
    prev index = j - 1

    Why j - 1?
    Because prev can be -1, and we cannot store negative index in DP.
    So we shift:
        prev = -1  → j = 0
        prev = 0   → j = 1
        prev = 1   → j = 2
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();

        /*
            dp size:
            rows → curr index (0 to n)
            cols → prev + 1 (to handle prev = -1 case)
        */
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        /*
            Fill DP from bottom (reverse order)
            because dp[i] depends on dp[i+1]
        */
        for (int i = n - 1; i >= 0; i--)
        {

            /*
                j represents previous index (shifted by +1)
                so actual prev = j - 1

                j goes from i-1 to -1
            */
            for (int j = i - 1; j >= -1; j--)
            {

                int include = 0;

                /*
                    Include condition:
                    - if no previous element (j == -1)
                    - OR current element is greater than previous
                */
                if (j == -1 || nums[j] < nums[i])
                {

                    /*
                        include = 1 + dp[i+1][i]

                        But since we are shifting index:
                        prev = i → store at (i + 1)

                        So:
                        dp[i+1][i+1]
                    */
                    include = 1 + dp[i + 1][i + 1]; // shifting used here
                }

                /*
                    Exclude current element:
                    prev remains same

                    dp[i+1][j+1]
                    (j+1 used because of shifting prev index)
                */
                int exclude = 0 + dp[i + 1][j + 1]; // shifting used here

                /*
                    Store result:
                    dp[i][j+1] because j can be -1

                    j = -1 → index 0
                    j = 0  → index 1
                */
                dp[i][j + 1] = max(include, exclude); // shifting used here
            }
        }

        /*
            Final answer:
            curr = 0, prev = -1 → shifted index = 0
        */
        return dp[0][0];
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