// Climbing Stairs -- (LC) Not Optimized
// # using recursion

#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int ways = climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;

    return 0;
}

// output
//  Enter number of stairs: 3
//  Number of ways to climb 3 stairs: 3
