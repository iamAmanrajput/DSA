// Leetcode Problem 1155. Number of Dice Rolls With Target Sum
/* TC: O(k^n)
   In the worst case, every die roll explores 'k' possibilities
   for 'n' dice, leading to an exponential tree.

   SC: O(n)
   Due to the recursion stack depth (equal to the number of dice).
*/
#include <iostream>
using namespace std;

class Solution
{
public:
    long long int MOD = 1000000007;

    // Pure Recursive Function
    int solve(int n, int k, int target)
    {
        // Base Case: If no dice left and target is reached
        if (target == 0 && n == 0)
        {
            return 1;
        }
        // Base Case: Target not reached but no dice left
        if (target != 0 && n == 0)
        {
            return 0;
        }
        // Base Case: Dice left but target is already 0 (or exceeded)
        if (target <= 0 && n != 0)
        {
            return 0;
        }

        int ans = 0;
        // Try every face of the die from 1 to k
        for (int i = 1; i <= k; i++)
        {
            // Recursive call for the remaining dice and reduced target
            int recAns = solve(n - 1, k, target - i) % MOD;
            ans = (ans + recAns) % MOD;
        }

        return ans;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        return solve(n, k, target);
    }
};

int main()
{
    Solution sol;

    // Test Case: n = 2, k = 6, target = 7
    int n = 2, k = 6, target = 7;

    // Note: Pure recursion will be very slow for large n and target values.
    int result = sol.numRollsToTarget(n, k, target);

    cout << "Test Case Result (n=2, k=6, target=7): " << result << endl;

    return 0;
}