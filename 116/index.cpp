// 53. Maximum Subarray --(LC)
// Divide and Conquer Approach

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper function to compute max subarray sum using divide and conquer
int maxSumArrayHelper(vector<int> &nums, int start, int end)
{
    if (start == end)
    {
        return nums[start];
    }

    int mid = start + (end - start) / 2;

    // Recursive calls for left and right halves
    int maxLeftSum = maxSumArrayHelper(nums, start, mid);
    int maxRightSum = maxSumArrayHelper(nums, mid + 1, end);

    // Compute max cross-border sum
    int maxLeftBorderSum = INT_MIN, leftBorderSum = 0;
    for (int i = mid; i >= start; i--)
    {
        leftBorderSum += nums[i];
        maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
    }

    int maxRightBorderSum = INT_MIN, rightBorderSum = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        rightBorderSum += nums[i];
        maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
    }

    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    // Return the maximum of the three
    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

// Main function that wraps the helper
int maxSubArray(vector<int> &nums)
{
    return maxSumArrayHelper(nums, 0, nums.size() - 1);
}

// Procedural main function
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int maxSum = maxSubArray(nums);
    cout << "Maximum Subarray Sum is: " << maxSum << endl;

    return 0;
}

// Input
// Enter number of elements: 5
// Enter elements:
// -2 1 -3 4 -1

// Output
// Maximum Subarray Sum is: 4