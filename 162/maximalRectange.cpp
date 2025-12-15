// Leetcode Problem 85. Maximal Rectangle
// Hint - use Maximum Area in a Histogram

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find index of previous smaller element for each bar
    vector<int> prevSmaller(vector<int> &v)
    {
        stack<int> st;
        st.push(-1); // sentinel for no smaller element

        vector<int> ans(v.size());

        for (int i = 0; i < v.size(); i++)
        {
            int curr = v[i];

            // pop until we find a smaller element
            while (st.top() != -1 && v[st.top()] >= curr)
            {
                st.pop();
            }

            // top of stack is previous smaller
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    // Function to find index of next smaller element for each bar
    vector<int> nextSmaller(vector<int> &v)
    {
        vector<int> ans(v.size());
        stack<int> s;
        s.push(-1); // sentinel

        for (int i = v.size() - 1; i >= 0; i--)
        {
            int curr = v[i];

            // pop until we find a smaller element
            while (s.top() != -1 && v[s.top()] >= curr)
            {
                s.pop();
            }

            // top of stack is next smaller
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    // Function to calculate largest rectangle area in histogram
    int largestRectangleArea(vector<int> &heights)
    {

        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN;

        for (int i = 0; i < heights.size(); i++)
        {
            int length = heights[i];

            // if no next smaller, take array size
            if (next[i] == -1)
            {
                next[i] = heights.size();
            }

            // width = right boundary - left boundary - 1
            int width = next[i] - prev[i] - 1;

            int area = length * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    // Function to find maximal rectangle of 1's in binary matrix
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        // edge case
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));

        // convert char matrix ('0','1') to int matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                v[i][j] = matrix[i][j] - '0';
            }
        }

        // calculate area for first row
        int area = largestRectangleArea(v[0]);

        // build histogram row by row
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 1)
                {
                    // add height from previous row
                    v[i][j] = v[i - 1][j] + 1;
                }
                else
                {
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main()
{
    Solution sol;

    // Test case: binary matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    int result = sol.maximalRectangle(matrix);

    cout << "Maximal Rectangle Area: " << result << endl;

    return 0;
}
