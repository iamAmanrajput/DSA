// Function to find GCD of two numbers using Euclids Algorith (GFG)

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return (a == 0) ? b : a;
}

int main()
{
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}

// input
// Enter two positive integers: 72
// 24

// output
//  GCD of 72 and 24 is: 24