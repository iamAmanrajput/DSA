// Implement Merge Sort Using Temp vector extra space
// TC 0(N (log N))
// SC 0(N)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to merge two sorted halves
    void merge(vector<int> &v, vector<int> &temp,
               int start, int mid, int end)
    {

        int i = start;   // Pointer for left half
        int j = mid + 1; // Pointer for right half
        int k = start;   // Pointer for temp array

        // Compare elements from both halves
        while (i <= mid && j <= end)
        {

            if (v[i] <= v[j])
                temp[k++] = v[i++]; // Copy smaller element from left
            else
                temp[k++] = v[j++]; // Copy smaller element from right
        }

        // Copy remaining elements from left half
        while (i <= mid)
            temp[k++] = v[i++];

        // Copy remaining elements from right half
        while (j <= end)
            temp[k++] = v[j++];

        // Copy merged elements back to original array
        while (start <= end)
        {
            v[start] = temp[start];
            start++;
        }
    }

    // Recursive merge sort function
    void mergeSort(vector<int> &v, vector<int> &temp,
                   int start, int end)
    {

        // Base case:
        // If only one element or invalid range, array is already sorted
        if (start >= end)
            return;

        // Find middle index
        int mid = (start + end) >> 1;

        // Recursively sort left half
        mergeSort(v, temp, start, mid);

        // Recursively sort right half
        mergeSort(v, temp, mid + 1, end);

        // Merge both sorted halves
        merge(v, temp, start, mid, end);
    }

    // Main sorting function
    vector<int> sortArray(vector<int> &nums)
    {

        // Temporary array used during merge operation
        vector<int> temp(nums.size());

        // Start merge sort
        mergeSort(nums, temp, 0, nums.size() - 1);

        return nums;
    }
};

int main()
{

    // Test case
    vector<int> arr = {8, 4, 2, 6, 1, 9, 3};

    Solution obj;

    // Sort array using merge sort
    vector<int> ans = obj.sortArray(arr);

    // Print sorted array
    cout << "Sorted Array: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}