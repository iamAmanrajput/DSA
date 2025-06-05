// 1155. Number of Dice Rolls With Target Sum -- (LC)

#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    // base case
    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n != 0 && target == 0)
        return 0;
    if (n == 0 && target != 0)
        return 0;

    int ans = 0;

    for (int i = 1; i <= k; i++)
    {
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}

int main()
{
    int n, k, target;
    cout << "Enter number of dice (n): ";
    cin >> n;
    cout << "Enter number of faces (k): ";
    cin >> k;
    cout << "Enter target sum: ";
    cin >> target;

    int result = numRollsToTarget(n, k, target);
    cout << "Number of ways: " << result << endl;

    return 0;
}

// Input: n = 1, k = 6, target = 3
// Output: 1
// Explanation: You throw one die with 6 faces.
// There is only one way to get a sum of 3.