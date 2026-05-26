// Second Way To Do Quick Sort

#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = e; // last index ko pivot choose kiya
    int i = s - 1; // pivot se chhote elements ki last position track karega
    int j = s;     // traversal ke liye pointer

    // Traverse array till pivot position
    while (j < pivot)
    {
        // Agar current element pivot se chhota hai
        if (arr[j] < arr[pivot])
        {
            i++;

            // Chhote element ko left side move karo
            swap(arr[i], arr[j]);
        }

        // Next element check karo
        j++;
    }

    // Pivot ko uski correct sorted position pe place karo
    i++;
    swap(arr[i], arr[pivot]);

    return i; // final pivot index return karo
}

void quickSort(int *arr, int s, int e)
{
    // Base case:
    // Agar 0 ya 1 element bacha hai to already sorted hai
    if (s >= e)
        return;

    // Partition karke pivot ki correct position nikalo
    int p = partition(arr, s, e);

    // Pivot ke left side ko sort karo
    quickSort(arr, s, p - 1);

    // Pivot ke right side ko sort karo
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 1, 3, 4, 20, 50, 30};
    int n = 7;

    // Complete array ko sort karo
    quickSort(arr, 0, n - 1);

    // Sorted array print karo
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}