// 287. Find the Duplicate Number --(LC)
// Visited Method

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find the duplicate number
int findDuplicate(vector<int> &nums)
{
    int ans = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);

        if (nums[index - 1] < 0)
        {
            ans = index;
            break;
        }

        nums[index - 1] *= -1;
    }

    return ans;
}

// Driver code
int main()
{
    // Input array with one duplicate from 1 to n
    vector<int> nums = {1, 3, 4, 2, 2};

    int duplicate = findDuplicate(nums);

    cout << "Duplicate element is: " << duplicate << endl;

    return 0;
}
