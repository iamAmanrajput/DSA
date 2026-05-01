// Leetcode 994. Rotting Oranges
// Time Complexity: O(m * n)
// - Har cell maximum ek baar visit hota hai

// Space Complexity: O(m * n)
// - visited array + queue worst case me saare cells store kar sakta hai
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem: Rotting Oranges (Leetcode 994)

Approach (BFS):
- Sabhi rotten oranges (2) ko queue me daal do as starting points (multi-source BFS)
- Har minute me adjacent (up, down, left, right) fresh oranges ko rotten banate jao
- Time track karne ke liye queue me {cell, time} store kar rahe hain
- Last me check karenge koi fresh orange (1) bach gaya ya nahi
*/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // visited array to track processed cells
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // queue for BFS -> stores {{row, col}, time}
        queue<pair<pair<int, int>, int>> Q;

        // Step 1: push all rotten oranges into queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    Q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;

        // Step 2: BFS traversal
        while (!Q.empty())
        {
            auto data = Q.front().first;
            int i = data.first;
            int j = data.second;
            int time = Q.front().second;
            Q.pop();

            ans = max(ans, time);

            // check all 4 directions

            // up
            if ((i - 1 >= 0) && (!vis[i - 1][j]) && (grid[i - 1][j] == 1))
            {
                vis[i - 1][j] = true;
                Q.push({{i - 1, j}, time + 1});
            }

            // down
            if ((i + 1 < m) && (!vis[i + 1][j]) && (grid[i + 1][j] == 1))
            {
                vis[i + 1][j] = true;
                Q.push({{i + 1, j}, time + 1});
            }

            // left
            if ((j - 1 >= 0) && (!vis[i][j - 1]) && (grid[i][j - 1] == 1))
            {
                vis[i][j - 1] = true;
                Q.push({{i, j - 1}, time + 1});
            }

            // right
            if ((j + 1 < n) && (!vis[i][j + 1]) && (grid[i][j + 1] == 1))
            {
                vis[i][j + 1] = true;
                Q.push({{i, j + 1}, time + 1});
            }
        }

        // Step 3: check if any fresh orange is left
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((grid[i][j] == 1) && (vis[i][j] == false))
                {
                    ans = -1; // impossible case
                }
            }
        }

        return ans;
    }
};

// Main function for testing
int main()
{
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    cout << "Output 1: " << sol.orangesRotting(grid1) << endl; // Expected: 4

    // Test Case 2 (edge case)
    vector<vector<int>> grid2 = {
        {0}};
    cout << "Output 2: " << sol.orangesRotting(grid2) << endl; // Expected: 0

    // Test Case 3 (impossible case)
    vector<vector<int>> grid3 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}};
    cout << "Output 3: " << sol.orangesRotting(grid3) << endl; // Expected: -1

    return 0;
}