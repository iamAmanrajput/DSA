// Leetcode Problem 84. Largest Rectangle in Histogram

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // ---------------------- PREVIOUS SMALLER ELEMENT ----------------------
    // For each index i, find the nearest element on the LEFT which is smaller.
    vector<int> prevSmaller(vector<int> &v)
    {
        stack<int> st;
        st.push(-1); // If no smaller element exists → -1

        vector<int> ans(v.size());

        for (int i = 0; i < v.size(); i++)
        {
            int curr = v[i];

            // Pop until a smaller element is found
            while (st.top() != -1 && v[st.top()] >= curr)
            {
                st.pop();
            }

            // Top now contains the index of previous smaller element
            ans[i] = st.top();

            // Push current index to stack
            st.push(i);
        }

        return ans;
    }

    // ---------------------- NEXT SMALLER ELEMENT ----------------------
    // For each index i, find the nearest element on the RIGHT which is smaller.
    vector<int> nextSmaller(vector<int> &v)
    {
        vector<int> ans(v.size());
        stack<int> s;
        s.push(-1); // If no smaller element exists → -1

        for (int i = v.size() - 1; i >= 0; i--)
        {

            int curr = v[i];

            // Pop until a smaller element is found on the right
            while (s.top() != -1 && v[s.top()] >= curr)
            {
                s.pop();
            }

            // Top now contains the index of next smaller element
            ans[i] = s.top();

            // Push current index to stack
            s.push(i);
        }

        return ans;
    }

    // ---------------------- LARGEST RECTANGLE IN HISTOGRAM ----------------------
    int largestRectangleArea(vector<int> &heights)
    {

        // Prev and Next Smaller Element
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN;

        for (int i = 0; i < heights.size(); i++)
        {

            int height = heights[i];

            // If no smaller element on right → set next[i] to n
            if (next[i] == -1)
            {
                next[i] = next.size();
            }

            // Width = next smaller index - prev smaller index - 1
            int width = next[i] - prev[i] - 1;

            // Area = height * width
            int area = height * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;

    // Test Case
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area = "
         << sol.largestRectangleArea(heights) << endl;

    return 0;
}
