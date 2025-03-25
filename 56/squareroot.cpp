// Square Root of a number using binary search

#include <iostream>
using namespace std;

int main()
{
    int n = 10; // Number to find square root of

    // Binary Search to find integer part
    int start = 0, end = n;
    int ans = 0;
    int target = n;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid * mid > target)
        {
            end = mid - 1;
        }
        else if (mid * mid == target)
        {
            ans = mid;
            break;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    int precision = 3;

    double finalAns = ans;
    double step = 0.1;

    for (int i = 0; i < precision; i++)
    {

        for (double j = finalAns; j * j <= n; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << finalAns;

    return 0;
}