// Leetcode Problem 200. Number of Islands

// Approach:
// Poore grid ko traverse karo
// Jab bhi unvisited '1' mile → new island mila
// DFS call karo aur poore island ko mark kar do
// Har DFS call ke baad island count +1

// Time Complexity (TC):
// O(m * n)
// Har cell ek baar visit hota hai

// Space Complexity (SC):
// O(m * n) → visited array
// + recursion stack (worst case)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // DFS function to explore whole island
    void dfs(int i, int j, vector<vector<bool>> &vis,
             vector<vector<char>> &grid, int m, int n)
    {

        // Base condition: out of bounds / already visited / water
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] != '1')
        {
            return;
        }

        // Mark current cell as visited
        vis[i][j] = true;

        // Explore all 4 directions
        dfs(i - 1, j, vis, grid, m, n); // top
        dfs(i, j + 1, vis, grid, m, n); // right
        dfs(i + 1, j, vis, grid, m, n); // bottom
        dfs(i, j - 1, vis, grid, m, n); // left
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;

        int m = grid.size();    // rows
        int n = grid[0].size(); // columns

        // Visited matrix to track visited cells
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Traverse entire grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // If land found and not visited → new island
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(i, j, vis, grid, m, n); // explore whole island
                    islands++;                  // count island
                }
            }
        }

        return islands;
    }
};

int main()
{
    Solution obj;

    // Test case
    vector<vector<char>> grid = {
        {'1', '1', '0', '0'},
        {'1', '0', '0', '1'},
        {'0', '0', '1', '1'},
        {'0', '0', '0', '0'}};

    int result = obj.numIslands(grid);

    cout << "Number of Islands: " << result << endl;

    return 0;
}