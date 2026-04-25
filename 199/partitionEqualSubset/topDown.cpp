// Leetcode problem 416. Partition Equal Subset Sum
// TC: O(n * target) - Each state (index, target) is computed once.
// SC: O(n * target) - DP table size + O(n) recursion stack.
#include <iostream>
#include <vector>

using namespace std;

bool solveUsingMem(vector<int> &arr, int index, int sum, int target, vector<vector<int>> &dp)
{
    // Base Case: Agar index array ke bahar chala gaya
    if (index >= arr.size())
    {
        return 0;
    }
    // Base Case: Agar current sum target se zyada ho gaya
    if (sum > target)
    {
        return 0;
    }
    // Base Case: Agar target mil gaya
    if (sum == target)
    {
        return true;
    }

    // Check if result is already computed
    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    // Recursion: Include current element or Exclude it
    bool include = solveUsingMem(arr, index + 1, sum + arr[index], target, dp);
    bool exclude = solveUsingMem(arr, index + 1, sum, target, dp);

    // Memoize and return
    return dp[index][sum] = (include || exclude);
}

int main()
{
    // Test Case 1: Possible to partition {1, 5, 11, 5} into {1, 5, 5} and {11}
    vector<int> arr1 = {1, 5, 11, 5};
    int totalSum1 = 0;
    for (int i : arr1)
        totalSum1 += i;

    cout << "Test Case 1: ";
    if (totalSum1 % 2 != 0)
    {
        cout << "False" << endl;
    }
    else
    {
        int target1 = totalSum1 / 2;
        vector<vector<int>> dp1(arr1.size(), vector<int>(target1 + 1, -1));
        cout << (solveUsingMem(arr1, 0, 0, target1, dp1) ? "True" : "False") << endl;
    }

    // Test Case 2: Impossible to partition {1, 2, 3, 5}
    vector<int> arr2 = {1, 2, 3, 5};
    int totalSum2 = 0;
    for (int i : arr2)
        totalSum2 += i;

    cout << "Test Case 2: ";
    if (totalSum2 % 2 != 0)
    {
        cout << "False" << endl;
    }
    else
    {
        int target2 = totalSum2 / 2;
        vector<vector<int>> dp2(arr2.size(), vector<int>(target2 + 1, -1));
        cout << (solveUsingMem(arr2, 0, 0, target2, dp2) ? "True" : "False") << endl;
    }

    return 0;
}