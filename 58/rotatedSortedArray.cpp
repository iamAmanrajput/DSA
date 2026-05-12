// Leetcode Problem 33. Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Find the pivot point in the rotated sorted array
    int findPivot(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            // Check if mid is the pivot
            if (mid < e && arr[mid] > arr[mid + 1])
            {
                return mid;
            }

            // Check if mid-1 is the pivot
            if (mid > s && arr[mid - 1] > arr[mid])
            {
                return mid - 1;
            }

            // If left part is sorted, pivot must be in right part
            if (arr[s] <= arr[mid])
            {
                s = mid + 1;
            }
            // Otherwise pivot is in left part
            else
            {
                e = mid - 1;
            }
        }

        // If no pivot is found, array is not rotated
        return -1;
    }

    // Standard Binary Search
    int binarySearch(vector<int> &arr, int s, int e, int target)
    {

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            // Target found
            if (arr[mid] == target)
            {
                return mid;
            }

            // Search in right half
            if (arr[mid] < target)
            {
                s = mid + 1;
            }
            // Search in left half
            else
            {
                e = mid - 1;
            }
        }

        // Target not found
        return -1;
    }

    int search(vector<int> &nums, int target)
    {

        // Find pivot index
        int pivotIndex = findPivot(nums);

        // If array is not rotated
        if (pivotIndex == -1)
        {
            return binarySearch(nums, 0, nums.size() - 1, target);
        }

        // Target lies in first sorted part
        if (target >= nums[0] && target <= nums[pivotIndex])
        {
            return binarySearch(nums, 0, pivotIndex, target);
        }

        // Target lies in second sorted part
        return binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int ans = obj.search(nums, target);

    cout << "Target found at index: " << ans << endl;

    return 0;
}