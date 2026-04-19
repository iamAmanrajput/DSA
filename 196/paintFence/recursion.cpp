// GFG Problem Painting the Fence
// Time Complexity: O(2^n)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

class Solution
{
public:
    // Recursive function to calculate number of ways
    int solve(int n, int k)
    {

        // Base case: 1 post → k ways
        if (n == 1)
        {
            return k;
        }

        // Base case: 2 posts → k + k*(k-1) = k^2 ways
        if (n == 2)
        {
            return (k + k * (k - 1));
        }

        // Recurrence relation:
        // (ways of n-1 + ways of n-2) * (k-1)
        // same + diff
        int ans = (solve(n - 1, k) + solve(n - 2, k)) * (k - 1);

        return ans;
    }

    // Main function
    int countWays(int n, int k)
    {
        return solve(n, k);
    }
};

/*
Problem:
Given a fence with n posts and k colours, find out the number of ways
of painting the fence so that not more than two consecutive posts
have the same colours.

Answers are guaranteed to fit into a 32-bit integer.
*/

int main()
{
    Solution obj;

    int n = 3;
    int k = 2;

    int result = obj.countWays(n, k);

    cout << "Number of ways to paint fence: " << result << endl;

    return 0;
}

// Output
// 6