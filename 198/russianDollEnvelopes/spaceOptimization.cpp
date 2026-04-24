// Leetcode Problem 354. Russian Doll Envelopes
//  Time Complexity: O(n^2) - Due to the nested loops in the tabulation approach.
//  Space Complexity: O(n) - Optimized space using only two rows (currRow and nextRow).
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: 354. Russian Doll Envelopes
 */

class Solution
{
public:
    // Helper function to check if the 'prev' envelope can fit inside the 'curr' envelope
    bool check(vector<int> &curr, vector<int> &prev)
    {
        // According to problem rules: both width and height must be strictly greater
        // curr -> larger envelope, prev -> smaller envelope
        if (prev[0] < curr[0] && prev[1] < curr[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Space Optimized Tabulation for Longest Increasing Subsequence (LIS) variation
    int solve(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();

        // Use two rows to save space: O(n) instead of O(n*n)
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        // Iterate backwards from the last envelope
        for (int curr_index = n - 1; curr_index >= 0; curr_index--)
        {
            // prev_index goes from curr-1 down to -1 (represented as index + 1 in the DP table)
            for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--)
            {

                int include = 0;
                // If it's the first envelope being picked or it fits the previous one
                if (prev_index == -1 || check(envelopes[curr_index], envelopes[prev_index]))
                {
                    include = 1 + nextRow[curr_index + 1];
                }

                // Option to skip the current envelope
                int exclude = nextRow[prev_index + 1];

                // Store the maximum result in currRow
                currRow[prev_index + 1] = max(include, exclude);
            }
            // Shifting: current row becomes the 'nextRow' for the next iteration
            nextRow = currRow;
        }

        return nextRow[0];
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // Step 1: Sort envelopes by width (and height as secondary) to process in order
        sort(envelopes.begin(), envelopes.end());

        // Step 2: Apply the DP-based LIS logic
        int ans = solve(envelopes);
        return ans;
    }
};

// Main function for testing
int main()
{
    Solution sol;

    // Test Case: [[5,4],[6,4],[6,7],[2,3]]
    // Sorted version: [[2,3], [5,4], [6,4], [6,7]]
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};

    int result = sol.maxEnvelopes(envelopes);

    cout << "Maximum number of Russian Doll envelopes: " << result << endl;
    // Expected output for this case: 3 ([2,3] -> [5,4] -> [6,7])

    return 0;
}