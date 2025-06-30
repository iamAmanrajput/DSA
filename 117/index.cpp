// Second Way to write Quick Sort

#include <iostream>
#include <vector>
using namespace std;

// QuickSort Function
void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = end;
    int i = start - 1;
    int j = start;

    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);

    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

// Input:
// Enter number of elements: 5
// Enter elements:
// 3 1 5 2 4

// Output:
// Sorted array: 1 2 3 4 5
