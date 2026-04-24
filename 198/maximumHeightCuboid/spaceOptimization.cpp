// Leetcode Problem 1691. Maximum Height by Stacking Cuboids
// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Helper function to check if the 'prev' cuboid can fit inside 'curr'
    bool check(vector<int> &curr, vector<int> &prev)
    {
        // Condition: Dimensions of the larger box (curr) must be >= dimensions of smaller box (prev)
        if (curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Space Optimized Tabulation approach for Longest Increasing Subsequence (LIS) variation
    int solveUsingTabulationSO(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();

        // currRow and nextRow represent the DP states for space optimization
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        // Iterate backwards through the cuboids
        for (int curr_index = n - 1; curr_index >= 0; curr_index--)
        {
            // prev_index tracks the previously picked cuboid in the stack
            for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--)
            {

                int include = 0;
                // Check if current cuboid can be placed on top of the 'prev' cuboid
                if (prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index]))
                {
                    // Include: add current height + the best height from the next state
                    include = cuboids[curr_index][2] + nextRow[curr_index + 1];
                }

                // Exclude: carry forward the best height from the next state without this cuboid
                int exclude = nextRow[prev_index + 1];

                // Store the maximum of including or excluding current cuboid
                currRow[prev_index + 1] = max(include, exclude);
            }
            // Move to the next row (Shifting)
            nextRow = currRow;
        }

        return nextRow[0];
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {
        // Step 1: Sort dimensions within each individual cuboid (to make the largest side the "height")
        for (auto &cuboid : cuboids)
        {
            sort(cuboid.begin(), cuboid.end());
        }

        // Step 2: Sort the entire list of cuboids based on dimensions
        sort(cuboids.begin(), cuboids.end());

        // Step 3: Find the maximum stacking height using DP
        int ans = solveUsingTabulationSO(cuboids);
        return ans;
    }
};

// Main function to test the code
int main()
{
    Solution sol;

    // Test case: [[50,45,20],[95,37,53],[45,23,12]]
    // After sorting internal dimensions: [[20,45,50], [37,53,95], [12,23,45]]
    // After sorting cuboids: [[12,23,45], [20,45,50], [37,53,95]]
    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};

    int result = sol.maxHeight(cuboids);

    cout << "Maximum stacking height: " << result << endl;

    return 0;
}