// Top Down Approach (Recursion + Memoization)
// TC O(N)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to calculate Fibonacci using Memoization (Top-Down DP)
    int solveUsingMemo(int n, vector<int> &dp)
    {

        // Base Case:
        // If n is 0 or 1, return n directly
        if (n == 0 || n == 1)
        {
            return n;
        }

        // Step 3: If answer already computed, return it
        // This avoids recomputation of same subproblem
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Recursive Relation:
        // fib(n) = fib(n-1) + fib(n-2)

        // Step 2: Store the computed result in dp array and return it
        dp[n] = solveUsingMemo(n - 1, dp) + solveUsingMemo(n - 2, dp);
        return dp[n];
    }

    int fib(int n)
    {

        // Step 1: Create DP array of size (n+1) and initialize with -1
        // -1 indicates that value is not yet computed
        vector<int> dp(n + 1, -1);

        // Call memoization function
        int ans = solveUsingMemo(n, dp);

        // Return final answer
        return ans;
    }
};

int main()
{
    Solution obj;

    // Test cases
    vector<int> testCases = {0, 1, 2, 3, 5, 10};

    cout << "Fibonacci using Memoization:\n";

    // Loop through test cases
    for (int n : testCases)
    {
        cout << "fib(" << n << ") = " << obj.fib(n) << endl;
    }

    return 0;
}