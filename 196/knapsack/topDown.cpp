// GFG Problem 0 - 1 Knapsack Problem
// Time Complexity: O(n * W)
// Space Complexity: O(n * W) + O(n) recursion stack

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Recursive + Memoization function
    int solve(int capacity, vector<int> &wt, vector<int> &val, int index, int n, vector<vector<int>> &dp)
    {

        // Base case:
        // If all items are processed, no value can be added
        if (index >= n)
        {
            return 0;
        }

        // If already computed, return stored result
        if (dp[capacity][index] != -1)
        {
            return dp[capacity][index];
        }

        // Include current item (if weight allows)
        int include = 0;
        if (wt[index] <= capacity)
        {
            include = val[index] + solve(capacity - wt[index], wt, val, index + 1, n, dp);
        }

        // Exclude current item
        int exclude = solve(capacity, wt, val, index + 1, n, dp);

        // Store and return maximum of both choices
        dp[capacity][index] = max(include, exclude);
        return dp[capacity][index];
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {

        int n = val.size();

        // DP array:
        // dp[capacity][index] → max value using items from index to n with given capacity
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));

        return solve(W, wt, val, 0, n, dp);
    }
};

/*
Problem (0/1 Knapsack):

Given:
- val[] → values of items
- wt[]  → weights of items
- W     → maximum capacity of knapsack

Goal:
Maximize total value such that total weight ≤ W

Constraints:
- Each item can be picked only once (0/1)
- Fractional selection not allowed

Approach:
- For each item, we have 2 choices:
    1. Include (if weight allows)
    2. Exclude
- Use memoization to store results of overlapping subproblems

State:
    dp[capacity][index]
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