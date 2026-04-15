// Bottom Up + Space Optimization
// TC 0(N)
// SC O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to calculate Fibonacci using Space Optimized DP
    int solveUsingTabulationSpaceOptimized(int n)
    {

        // Base case:
        // If n = 0, Fibonacci value is 0
        if (n == 0)
        {
            return 0;
        }

        // prev represents fib(0)
        int prev = 0;

        // curr represents fib(1)
        int curr = 1;

        // Variable to store current answer
        int ans;

        // Loop from 2 to n
        for (int i = 2; i <= n; i++)
        {

            // Calculate next Fibonacci number
            ans = curr + prev;

            // Shift values for next iteration
            prev = curr;
            curr = ans;
        }

        // Final answer stored in curr
        return curr;
    }

    int fib(int n)
    {
        return solveUsingTabulationSpaceOptimized(n);
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    int n1 = 5;
    cout << "Fib(" << n1 << ") = " << obj.fib(n1) << endl;

    // Test Case 2
    int n2 = 10;
    cout << "Fib(" << n2 << ") = " << obj.fib(n2) << endl;

    // Test Case 3 (Edge case)
    int n3 = 0;
    cout << "Fib(" << n3 << ") = " << obj.fib(n3) << endl;

    return 0;
}