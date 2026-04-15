// Bottom Up Approach (Tabulation Method)
// TC O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveUsingTabulation(int n)
    {

        // Step 1: Create a DP array of size (n + 1)
        // This array will store Fibonacci values from 0 to n
        vector<int> dp(n + 1, -1);

        // Step 2: Initialize base cases
        // We already know:
        // fib(0) = 0 and fib(1) = 1
        dp[0] = 0;
        if (n == 0)
        {
            return dp[0];
        }
        dp[1] = 1;

        // Step 3: Fill the DP array from index 2 to n
        // Each value depends on the previous two values
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Step 4: Return the final answer
        // The nth Fibonacci number is stored at dp[n]
        return dp[n];
    }

    int fib(int n)
    {
        // Call the tabulation function and return the result
        return solveUsingTabulation(n);
    }
};

int main()
{
    Solution obj;

    // Test cases
    cout << "fib(0): " << obj.fib(0) << endl;   // 0
    cout << "fib(1): " << obj.fib(1) << endl;   // 1
    cout << "fib(5): " << obj.fib(5) << endl;   // 5
    cout << "fib(10): " << obj.fib(10) << endl; // 55

    return 0;
}

// fib(0): 0
// fib(1): 1
// fib(5): 5
// fib(10): 55