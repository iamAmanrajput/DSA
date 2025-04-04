// print subarray using recursion

#include <iostream>
#include <vector>
using namespace std;

void printSubarr_util(vector<int> &nums, int start, int end)
{
    // base case
    if (end == nums.size())
    {
        return;
    }

    // handle one case
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    // recursive call
    printSubarr_util(nums, start, end + 1);
}

void printSubarr(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printSubarr_util(nums, start, end);
    }
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};

    printSubarr(nums);

    return 0;
}

// output

// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// 2
// 2 3
// 2 3 4
// 2 3 4 5
// 3
// 3 4
// 3 4 5
// 4
// 4 5
// 5