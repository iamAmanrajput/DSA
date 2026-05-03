// Leetcode Problem 733. Flood Fill
/*
====================== COMPLEXITY ======================

Time Complexity:
- In worst case, we visit all cells → O(m * n)

Space Complexity:
- Recursion stack (DFS) → O(m * n) worst case

=======================================================
*/
#include <bits/stdc++.h>
using namespace std;

/*
====================== PROBLEM ======================

Given an m x n grid (image), each cell represents a pixel color.

You are given:
- Starting point (sr, sc)
- A new color

Task:
Fill all connected pixels (4-directionally) having the same
original color as image[sr][sc] with the new color.

This is called Flood Fill.

====================================================
*/

class Solution
{
public:
    /*
    ==================================================
    FUNCTION: DFS (Depth First Search)

    - We start from (i, j)
    - Change its color to newColor
    - Visit all 4 directions (up, right, down, left)

    Base Conditions:
    - Out of bounds
    - Pixel not equal to original color

    ==================================================
    */
    void dfs(vector<vector<int>> &image, int i, int j,
             int newColor, int orgColor)
    {

        // Boundary + color check
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
            image[i][j] != orgColor || image[i][j] == newColor)
        {
            return;
        }

        // Fill current pixel
        image[i][j] = newColor;

        // Explore all 4 directions
        dfs(image, i - 1, j, newColor, orgColor); // top
        dfs(image, i, j + 1, newColor, orgColor); // right
        dfs(image, i + 1, j, newColor, orgColor); // bottom
        dfs(image, i, j - 1, newColor, orgColor); // left
    }

    /*
    ==================================================
    FUNCTION: floodFill

    Steps:
    1. Get original color
    2. If already same as new color → no work needed
    3. Call DFS
    ==================================================
    */
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int color)
    {

        int orgColor = image[sr][sc];

        // Edge case: already same color
        if (orgColor == color)
            return image;

        dfs(image, sr, sc, color, orgColor);

        return image;
    }
};

int main()
{
    Solution obj;

    /*
    Example Image:
    1 1 1
    1 1 0
    1 0 1
    */

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1, sc = 1;
    int newColor = 2;

    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

    // Print result
    cout << "Updated Image:\n";
    for (auto row : result)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}