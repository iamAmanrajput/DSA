// GFG Problem 0 - 1 Knapsack Problem
// Time Complexity: O(2^n) (not optimized)
// Space Complexity: O(n) (recursion stack)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Recursive function
    int solve(int capacity, vector<int> &wt, vector<int> &val, int index, int n)
    {
        // Base case:
        // If index goes beyond last item (all items processed),
        // no more items can be included, so return 0 value
        if (index >= n)
        {
            return 0;
        }

        // Include current item (if possible)
        int include = 0;
        if (wt[index] <= capacity)
        {
            include = val[index] + solve(capacity - wt[index], wt, val, index + 1, n);
        }

        // Exclude current item
        int exclude = solve(capacity, wt, val, index + 1, n);

        // Return maximum of both choices
        return max(include, exclude);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();

        // IMPORTANT: return karna zaroori hai
        return solve(W, wt, val, 0, n);
    }
};

/*
Problem (0/1 Knapsack):

Given two arrays:
- val[] → value of items
- wt[]  → weight of items
And an integer W → maximum capacity of knapsack

Goal:
Select items such that:
- Total weight ≤ W
- Total value is maximum

Constraints:
- Each item can be taken only once (0/1 choice)
- Fractional selection NOT allowed

Approach:
- For each item, we have 2 choices:
    1. Include it (if weight allows)
    2. Exclude it
- Use recursion to try all possibilities

*/

int main()
{
    Solution obj;

    // Test Case
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    cout << "Maximum value in Knapsack: "
         << obj.knapsack(W, val, wt) << endl;

    // Expected Output: 220

    return 0;
}