// In Place Merge Sort
// TC - O(N LOGN)
// SC - 0(1)

#include <iostream>
#include <vector>
using namespace std;

// In-place merge using Shell Sort-style gap method
void mergeInPlace(vector<int> &nums, int start, int mid, int end)
{
    int total_len = end - start + 1;
    int gap = (total_len / 2) + (total_len % 2); // ceil division

    while (gap > 0)
    {
        int i = start, j = start + gap;
        while (j <= end)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
            i++;
            j++;
        }

        // Recalculate next gap
        gap = (gap <= 1) ? 0 : (gap / 2) + (gap % 2);
    }
}

// Recursive merge sort using in-place merging
void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    mergeInPlace(nums, start, mid, end);
}

int main()
{
    vector<int> nums = {5, 2, 3, 1, 4};

    cout << "Original Array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    mergeSort(nums, 0, nums.size() - 1); // Directly calling merge sort

    cout << "Sorted Array (In-place): ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
