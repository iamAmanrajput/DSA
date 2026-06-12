// Count Inversion -- Hacker Rank
//  # Approach 2 -- MERGE SORT
// TC - (N LOGN)

#include <iostream>
using namespace std;

// Global variable to keep track of the number of inversions
long long inversionCount = 0;

/*
    This function merges two sorted halves of the array [s to mid] and [mid+1 to e],
    and while merging, it counts the number of inversions.
*/
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1; // Length of left half
    int len2 = e - mid;     // Length of right half

    // Create dynamic arrays to hold left and right subarrays
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy elements to left array
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    // Copy elements to right array
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    // Start merging left and right arrays back into original array
    int leftIndex = 0, rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] <= right[rightIndex])
        {
            // No inversion, just copy from left
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            // Inversion found: all remaining elements in left[] from leftIndex onward
            // are greater than right[rightIndex], which is an inversion.
            arr[mainArrayIndex++] = right[rightIndex++];
            inversionCount += (len1 - leftIndex); // Important step!
        }
    }

    // Copy any remaining elements from left[]
    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // Copy any remaining elements from right[]
    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // Free dynamically allocated memory
    delete[] left;
    delete[] right;
}

/*
    Recursively sorts the array using merge sort and calls merge() to count inversions
*/
void mergeSort(int *arr, int s, int e)
{
    // Base case: array of 1 or 0 elements is already sorted
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // Sort left half
    mergeSort(arr, s, mid);

    // Sort right half
    mergeSort(arr, mid + 1, e);

    // Merge the two sorted halves and count inversions
    merge(arr, s, e);
}

int main()
{
    // Sample input array
    int arr[] = {2, 1, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    // Call merge sort which also counts inversions
    mergeSort(arr, 0, n - 1);

    // Output the total inversion count
    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
