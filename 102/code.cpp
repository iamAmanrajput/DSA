// House Robber problem Leetcode
// using Recursion

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to calculate max loot
int robHelp(vector<int> &nums, int i)
{
    if (i >= nums.size())
    {
        return 0;
    }

    int rob1 = nums[i] + robHelp(nums, i + 2); // Rob current house
    int rob2 = robHelp(nums, i + 1);           // Skip current house

    return max(rob1, rob2);
}

// Rob function
int rob(vector<int> &nums)
{
    return robHelp(nums, 0);
}

// Main function with test case
int main()
{
    vector<int> houses = {2, 7, 9, 3, 1}; // Test case
    int maxLoot = rob(houses);
    cout << "Maximum money that can be robbed: " << maxLoot << endl;
    return 0;
}

// output
// Maximum money that can be robbed: 12
