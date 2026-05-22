// GFG PROBLEM - Stickler Theif
// Max Sum of Non - Adjacent Element

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Recursive + Memoization function
    int solve(vector<int> &arr, int i, vector<int> &dp)
    {

        // Base case:
        // Agar index array se bahar chala gaya to sum = 0
        if (i >= arr.size())
        {
            return 0;
        }

        // Agar pehle calculate ho chuka hai
        if (dp[i] != -1)
        {
            return dp[i];
        }

        // Include current element
        // Current value lo aur next adjacent skip karo
        int include = arr[i] + solve(arr, i + 2, dp);

        // Exclude current element
        // Current mat lo, next index pe jao
        int exclude = solve(arr, i + 1, dp);

        // Maximum answer store karke return
        return dp[i] = max(include, exclude);
    }

    int findMaxSum(vector<int> &arr)
    {

        // DP array initialize with -1
        vector<int> dp(arr.size() + 1, -1);

        return solve(arr, 0, dp);
    }
};

int main()
{

    // Test case
    vector<int> arr = {6, 7, 1, 3, 8, 2, 4};

    Solution obj;

    int ans = obj.findMaxSum(arr);

    cout << "Maximum Sum: " << ans << endl;

    return 0;
}