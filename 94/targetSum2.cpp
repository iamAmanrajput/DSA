// Adobe Problem -> find target sum using elements of array
// +ve Approach

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &arr, int target, int currentSum)
{
    // base case
    if (currentSum == target)
        return 0;

    if (currentSum > target)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solve(arr, target, currentSum + arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1); // +1 for current element
        }
    }

    return mini;
}

int main()
{
    vector<int> arr{1, 2};
    int target = 3;

    int ans = solve(arr, target, 0); // start with sum = 0

    if (ans == INT_MAX)
        cout << "No solution possible\n";
    else
        cout << "Ans is: " << ans << endl;

    return 0;
}
