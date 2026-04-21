// GFG Problem 0 - 1 Knapsack Problem
// Time Complexity: O(n * W)
// Space Complexity: O(n * W)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {

        int n = val.size();

        // DP array:
        // dp[i][j] → max value using capacity = i and items from j to n-1
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));

        // Base case:
        // When no items left (j == n), value = 0
        for (int row = 0; row <= W; row++)
        {
            dp[row][n] = 0;
        }

        // Fill DP table
        for (int i = 0; i <= W; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {

                // Include current item (if possible)
                int include = 0;
                if (wt[j] <= i)
                {
                    include = val[j] + dp[i - wt[j]][j + 1];
                }

                // Exclude current item
                int exclude = dp[i][j + 1];

                // Store maximum value
                dp[i][j] = max(include, exclude);
            }
        }

        // Final answer: full capacity and starting index 0
        return dp[W][0];
    }
};

/*
Problem: 0/1 Knapsack

Given:
- val[] → values of items
- wt[]  → weights of items
- W     → maximum capacity

Goal:
Maximize total value such that total weight ≤ W

Rules:
- Each item can be taken only once
- No fractional selection allowed

Approach:
- Bottom-Up DP (Tabulation)
- For each item, we have 2 choices:
    include or exclude
*/

int main()
{
    Solution obj;

    // Test Case 1
    vector<int> val1 = {60, 100, 120};
    vector<int> wt1 = {10, 20, 30};
    int W1 = 50;

    cout << "Test Case 1:" << endl;
    cout << "Maximum value = "
         << obj.knapsack(W1, val1, wt1) << endl;
    // Expected Output: 220

    cout << endl;

    // Test Case 2
    vector<int> val2 = {10, 40, 30, 50};
    vector<int> wt2 = {5, 4, 6, 3};
    int W2 = 10;

    cout << "Test Case 2:" << endl;
    cout << "Maximum value = "
         << obj.knapsack(W2, val2, wt2) << endl;
    // Expected Output: 90

    return 0;
}