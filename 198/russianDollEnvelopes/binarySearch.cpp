// Leetcode Problem 354. Russian Doll Envelopes (Binary Search Optimization)
// Time Complexity: O(n log n) - Sorting takes O(n log n) and LIS with binary search takes O(n log n).
// Space Complexity: O(n) - To store the tails/ans vector for LIS.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem: 354. Russian Doll Envelopes (Binary Search Optimization)

class Solution
{
public:
    // Custom comparator for sorting
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            // If widths are same, sort height in descending order
            return a[1] > b[1];
        }
        // Otherwise, sort width in ascending order
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n == 0)
            return 0;

        // Step 1: Sort the envelopes
        sort(envelopes.begin(), envelopes.end(), compare);

        // Step 2: Find LIS of the heights using Binary Search
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++)
        {
            int currentHeight = envelopes[i][1];

            if (currentHeight > ans.back())
            {
                // If current height is greater than the largest element in our LIS, append it
                ans.push_back(currentHeight);
            }
            else
            {
                // Otherwise, find the first element >= currentHeight and replace it
                // lower_bound uses binary search internally: O(log n)
                int index = lower_bound(ans.begin(), ans.end(), currentHeight) - ans.begin();
                ans[index] = currentHeight;
            }
        }

        return ans.size();
    }
};

int main()
{
    Solution sol;

    // Test Case: [[5,4],[6,4],[6,7],[2,3]]
    // After custom sort: [[2,3], [5,4], [6,7], [6,4]]
    // Heights to process: [3, 4, 7, 4]
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};

    int result = sol.maxEnvelopes(envelopes);

    cout << "Maximum number of Russian Doll envelopes: " << result << endl;
    // Output: 3

    return 0;
}