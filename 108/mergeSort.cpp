// Merge Sort Implementation With Recursion

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{

    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // making dynamic array
    int *left = new int[len1];
    int *right = new int[len2];

    // copy values in left part of array
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy values in right part of array
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // copy logic for left array
    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // copy logic for right array
    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // TODO : delete new created left and right dynamic array
    delete[] left;
    delete[] right;
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    // s == e -> single element
    // s > e -> invalid array
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // left part sort
    mergeSort(arr, s, mid);

    // right part sort
    mergeSort(arr, mid + 1, e);

    // now merge 2 sorted array
    merge(arr, s, e);
}

int main()
{
    int arr[] = {4, 5, 13, 2, 16};
    int n = 5;

    int s = 0;
    int e = n - 1;
    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
