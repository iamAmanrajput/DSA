// Brute Force Recursive Approach
// TC O(2^N)

#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to calculate nth Fibonacci number using recursion
    int fib(int n)
    {
        // Base case:
        // If n is 0 or 1, return n itself
        if (n == 0 || n == 1)
        {
            return n;
        }

        // Recursive case:
        // fib(n) = fib(n-1) + fib(n-2)
        int ans = fib(n - 1) + fib(n - 2);
        return ans;
    }
};

int main()
{
    Solution obj;

    // Test cases
    int testCases[] = {0, 1, 2, 3, 5, 10};

    cout << "Fibonacci Results:\n";

    // Loop through test cases
    for (int i = 0; i < 6; i++)
    {
        int n = testCases[i];
        cout << "fib(" << n << ") = " << obj.fib(n) << endl;
    }

    return 0;
}

// Fibonacci Results:
// fib(0) = 0
// fib(1) = 1
// fib(2) = 1
// fib(3) = 2
// fib(5) = 5
// fib(10) = 55