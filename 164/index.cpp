// Leetcode Problem 1776. Car Fleet II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars)
    {

        int n = cars.size();

        // answer[i] = time when ith car collides with next car
        vector<double> answer(n, -1);

        // stack stores indices of cars
        stack<int> st;

        // traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {

            // remove cars ahead which are faster or same speed
            // because collision is impossible
            while (!st.empty() && cars[st.top()][1] >= cars[i][1])
            {
                st.pop();
            }

            // check possible collision
            while (!st.empty())
            {

                // time = distance / relative speed
                double colTime =
                    (double)(cars[st.top()][0] - cars[i][0]) /
                    (cars[i][1] - cars[st.top()][1]);

                /*
                  Valid collision if:
                  - front car never collides (answer = -1), OR
                  - current collision happens before its collision
                */
                if (answer[st.top()] == -1 || colTime <= answer[st.top()])
                {
                    answer[i] = colTime;
                    break;
                }

                // otherwise front car collides earlier → remove it
                st.pop();
            }

            // push current car index
            st.push(i);
        }

        return answer;
    }
};

// ------------------ MAIN FUNCTION ------------------
int main()
{

    Solution sol;

    // Test case
    vector<vector<int>> cars = {
        {1, 2},
        {2, 1},
        {4, 3},
        {7, 2}};

    vector<double> result = sol.getCollisionTimes(cars);

    cout << "Collision Times:\n";
    for (double t : result)
    {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}

// Collision Times:
// 1 -1 1.5 -1
