// 279. Perfect Squares -- (LC)

#include <iostream>
#include <climits>
using namespace std;

int countMinSquares(int n)
{
    if (n == 0)
        return 0;

    int minCount = INT_MAX;

    for (int i = 1; i * i <= n; i++)
    {
        int square = i * i;
        int remaining = n - square;
        int count = 1 + countMinSquares(remaining);
        minCount = min(minCount, count);
    }

    return minCount;
}

int numSquares(int n)
{
    return countMinSquares(n);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Minimum number of perfect squares: " << numSquares(n) << endl;
    return 0;
}

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.