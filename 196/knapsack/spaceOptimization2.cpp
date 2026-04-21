// GFG Problem 0 - 1 Knapsack Problem
// TC O(N * W)
// SC O(W)
#include <bits/stdc++.h>
using namespace std;

/*
    Function: solveUsingTabulationSO2
    --------------------------------
    This function solves 0/1 Knapsack using space optimization (1D DP)

    capacity = max weight allowed
    wt[]     = weights of items
    profit[] = values of items
    n        = number of items
*/

int solveUsingTabulationSO2(int capacity, int wt[], int profit[], int n)
{

    // 1D DP array
    // next[i] = maximum profit for capacity i
    vector<int> next(capacity + 1, 0);

    // Traverse items from last to first
    for (int j = n - 1; j >= 0; j--)
    {

        // Traverse capacity in reverse (IMPORTANT)
        // Reverse loop prevents overwriting needed values
        for (int i = capacity; i >= 0; i--)
        {

            // Include current item (if possible)
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + next[i - wt[j]];
            }

            // Exclude current item
            int exclude = next[i];

            // Store maximum
            next[i] = max(include, exclude);
        }
    }

    // Final answer
    return next[capacity];
}

int main()
{

    int wt[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int capacity = 50;

    int n = sizeof(wt) / sizeof(wt[0]);

    int result = solveUsingTabulationSO2(capacity, wt, profit, n);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}

// Maximum Profit: 220