// Implementation of Heap Sort
#include <iostream>
using namespace std;

// Heapify function to maintain max heap property
void heapify(int arr[], int i, int n)
{
    int index = i;              // current node index
    int leftIndex = 2 * i;      // left child index
    int rightIndex = 2 * i + 1; // right child index
    int largest = index;        // assume current node is largest

    // check if left child exists and is greater than current largest
    if (leftIndex <= n && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }

    // check if right child exists and is greater than current largest
    if (rightIndex <= n && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }

    // if largest is not the current node, swap and recurse
    if (index != largest)
    {
        swap(arr[index], arr[largest]);

        // recursively heapify the affected subtree
        heapify(arr, largest, n);
    }
}

// Build heap from given array
void buildHeap(int arr[], int n)
{
    // start from last non-leaf node and heapify each node
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i, n);
    }
}

// Heap Sort function (1-based indexing assumed)
void heapSort(int arr[], int n)
{
    int index = n; // last element ka index

    // jab tak heap me 1 se zyada elements hain
    while (n != 1)
    {
        // step 1: root (largest element) ko last element se swap karo
        swap(arr[1], arr[index]);

        // step 2: last element apni correct position pe chala gaya
        index--;

        // step 3: heap ka size reduce karo
        n--;

        // step 4: root ko dobara heapify karo taaki max heap property maintain rahe
        heapify(arr, 1, n); // IMPORTANT: (index, size) → (1, n)
    }
}

int main()
{
    // using 1-based indexing, arr[0] is dummy
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;

    // build max heap
    buildHeap(arr, n);

    cout << "printing the heap " << endl;

    // print heap elements
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}