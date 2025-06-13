// QuickSort

#include <iostream>
using namespace std;

int partiton(int *arr, int s, int e)
{
    // step 1 -> choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // step 2 -> find the right position for the pivot element and place it there
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }

    // when i exit the loop, i have the right index of pivot element
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // step 3 -> place small elements in left and big elements in right

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        { // (<=) to handle the same values case
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // 2 case ho sakte hai
        // A-> you found thee element to swap
        // B -> No need to swap
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    // partition logic , return pivot index
    int p = partiton(arr, s, e);

    // pivot element left
    quickSort(arr, s, p - 1);

    // pivot element right
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[] = {8, 1, 3, 4, 20, 50, 30};
    int n = 7;
    int s = 0;
    int e = n - 1;

    quickSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}