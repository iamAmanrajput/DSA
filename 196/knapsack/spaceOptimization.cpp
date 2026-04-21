// GFG Problem 0 - 1 Knapsack Problem
// TC O(N * W)
// SC O(W)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {

        int n = val.size();

        // next = dp for next item (i+1)
        vector<int> next(W + 1, 0);

        // curr = dp for current item (i)
        vector<int> curr(W + 1, 0);

        // Traverse items from last to first
        for (int j = n - 1; j >= 0; j--)
        {

            // Traverse all capacities from 0 to W
            for (int i = 0; i <= W; i++)
            {

                // Case 1: Include current item (if possible)
                int include = 0;
                if (wt[j] <= i)
                {
                    include = val[j] + next[i - wt[j]];
                }

                // Case 2: Exclude current item
                int exclude = next[i];

                // Take maximum of include and exclude
                curr[i] = max(include, exclude);
            }

            // Move current row to next for next iteration
            next = curr;
        }

        // Final answer stored at full capacity W
        return next[W];
    }
};

int main()
{
    Solution obj;

    // Example test case
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    int result = obj.knapsack(W, val, wt);

    cout << "Maximum Value: " << result << endl;

    return 0;
}

// Maximum Value : 220