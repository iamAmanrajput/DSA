// Gfg Problem The Celebrity Problem
// TC - 0(N)
// VERY IMPORTANT PROBLEM

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        stack<int> st;
        int n = mat.size();

        if (n == 0)
            return -1; // handle empty matrix

        // step 1 : Push All Persons into stack
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // step 2 : run discard method , to get a mightBeCelebrity
        while (st.size() != 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            // if a knows b -> a cannot be celeb, b might be
            if (mat[a][b])
            {
                st.push(b);
            }
            else
            {
                // else b cannot be celeb, a might be
                st.push(a);
            }
        }

        // step 3 : check the single person is actually celebrity
        int mightbecelebrity = st.top();
        st.pop();

        // celeb should not know anyone (ignore self)
        for (int i = 0; i < n; i++)
        {
            if (i == mightbecelebrity)
                continue; // <- ignore diagonal
            if (mat[mightbecelebrity][i] != 0)
            {
                return -1;
            }
        }

        // everyone should know celebrity (ignore self)
        for (int i = 0; i < n; i++)
        {
            if (i == mightbecelebrity)
                continue; // <- ignore diagonal
            if (mat[i][mightbecelebrity] == 0)
            {
                return -1;
            }
        }

        return mightbecelebrity;
    }
};

int main()
{
    // -------------------------------
    // TEST CASE 1 (from your example)
    // n = 3
    // mat =
    // 1 1 0
    // 0 1 0
    // 0 1 1
    // Expected output: 1
    // -------------------------------
    vector<vector<int>> mat1 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}};

    Solution sol;
    int res1 = sol.celebrity(mat1);
    cout << "Test case 1 output: " << res1 << "  (expected 1)" << endl;

    // -------------------------------
    // Optional extra test case
    // n = 3
    // mat =
    // 0 0 0
    // 0 0 0
    // 0 0 0
    // No celebrity because everyone doesn't know anyone but also nobody is known by all -> -1
    // -------------------------------
    vector<vector<int>> mat2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    int res2 = sol.celebrity(mat2);
    cout << "Test case 2 output: " << res2 << "  (expected -1)" << endl;

    return 0;
}
