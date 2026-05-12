// Leetcode Problem 29 divide two integers
#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        // Handle overflow case
        // INT_MIN / -1 => value goes out of int range
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert into long long
        // because abs(INT_MIN) cannot be stored in int
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long start = 0;
        long long end = a;
        long long ans = 0;

        // Binary Search
        while (start <= end)
        {

            long long mid = start + (end - start) / 2;

            // Perfect quotient found
            if (mid * b == a)
            {
                ans = mid;
                break;
            }

            // Possible answer
            if (mid * b < a)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        // If signs are different => negative answer
        bool isNegative = (dividend < 0) != (divisor < 0);

        return isNegative ? -ans : ans;
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    cout << obj.divide(10, 3) << endl;
    // Output: 3

    // Test Case 2
    cout << obj.divide(25, 5) << endl;
    // Output: 5

    // Test Case 3
    cout << obj.divide(7, -2) << endl;
    // Output: -3

    // Test Case 4
    cout << obj.divide(-20, 4) << endl;
    // Output: -5

    // Test Case 5
    cout << obj.divide(-15, -3) << endl;
    // Output: 5

    return 0;
}