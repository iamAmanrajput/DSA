// Implementation of Max Heap with Insertion and Deletion

#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[101]; // Array to store heap elements (1-based indexing)
    int size;     // Current number of elements in heap
    int capacity; // Maximum capacity of heap

    // Constructor to initialize heap
    Heap()
    {
        size = 0;
        capacity = 100;
    }

    // Function to insert a new value into heap
    void insert(int value)
    {
        // Check if heap is full
        if (size >= capacity)
        {
            cout << "Heap Overflow! Cannot insert " << value << endl;
            return;
        }

        // Step 1: Insert value at the end of heap
        size++;
        int index = size;
        arr[index] = value;

        // Step 2: Heapify Up (Bubble Up)
        // Move the inserted element upwards until heap property is satisfied
        while (index > 1)
        {
            int parentIndex = index / 2;

            // If current node is greater than parent → swap
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);

                // Move to parent index
                index = parentIndex;
            }
            else
            {
                // Correct position found
                break;
            }
        }
    }

    // Function to delete root element from heap
    int deleteFromHeap()
    {
        // Check if heap is empty
        if (size == 0)
        {
            cout << "Heap Underflow! Nothing to delete" << endl;
            return -1;
        }

        // Step 1: Store root value (maximum element in max heap)
        int deletedValue = arr[1];

        // Step 2: Replace root with last element
        arr[1] = arr[size];

        // Reduce heap size
        size--;

        // Step 3: Heapify Down (Bubble Down)
        // Move the root element downwards to maintain heap property
        int index = 1;

        while (true)
        {
            int left = 2 * index;      // Left child index
            int right = 2 * index + 1; // Right child index
            int largest = index;       // Assume current index is largest

            // Check if left child exists and is greater than current
            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }

            // Check if right child exists and is greater than current
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }

            // If current node is already largest → heap property satisfied
            if (largest == index)
            {
                break;
            }

            // Otherwise, swap with the larger child
            swap(arr[index], arr[largest]);

            // Move index to the child position
            index = largest;
        }

        // Return deleted root value
        return deletedValue;
    }

    // Function to print heap elements
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;

    // Insert elements into heap
    cout << "Inserting elements...\n";
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // Print heap after insertion
    cout << "Heap after insertion: ";
    h.print();

    // Delete root element
    cout << "\nDeleting root element...\n";
    int deleted = h.deleteFromHeap();
    cout << "Deleted element: " << deleted << endl;

    // Print heap after deletion
    cout << "Heap after deletion: ";
    h.print();

    // Delete all elements one by one
    cout << "\nDeleting all elements one by one:\n";
    while (h.size > 0)
    {
        cout << "Deleted: " << h.deleteFromHeap() << endl;
    }

    // Try deleting from empty heap (underflow case)
    cout << "\nTrying to delete from empty heap:\n";
    h.deleteFromHeap();

    return 0;
}