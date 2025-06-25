// Merge Sort Implementation -- Using Temp Vector

#include <iostream>
#include <vector>
using namespace std;

// Two sorted halves ko merge karta hai: nums[start...mid] and nums[mid+1...end]
void merge(vector<int> &nums, vector<int> &temp, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;

    // Compare karke temp array me sorted values fill karna
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }

    // Agar left part me elements bache ho
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }

    // Agar right part me elements bache ho
    while (j <= end)
    {
        temp[k++] = nums[j++];
    }

    // Temp se wapas original array me copy karna
    while (start <= end)
    {
        nums[start] = temp[start];
        start++;
    }
}

// Array ko divide aur sort karne wala merge sort function
void mergeSort(vector<int> &nums, vector<int> &temp, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(nums, temp, start, mid);   // Left half
    mergeSort(nums, temp, mid + 1, end); // Right half
    merge(nums, temp, start, mid, end);  // Merge both
}

int main()
{
    vector<int> nums = {5, 2, 3, 1, 4};
    vector<int> temp(nums.size(), 0); // Temporary array

    // Original array print
    cout << "Original Array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    // Merge sort call
    mergeSort(nums, temp, 0, nums.size() - 1);

    // Sorted array print
    cout << "Sorted Array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
