// Insertion in Max Heap

#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[101]; // Heap array (1-based indexing)
    int size;     // Current number of elements
    int capacity; // Maximum capacity of heap

    // Constructor
    Heap()
    {
        size = 0;
        capacity = 100; // Max elements allowed
    }

    // Insert function
    void insert(int value)
    {
        // Overflow Check
        if (size >= capacity)
        {
            cout << "Heap Overflow! Cannot insert " << value << endl;
            return;
        }

        // Step 1: Insert value at the end
        size = size + 1;
        int index = size;
        arr[index] = value;

        // Step 2: Heapify Up (Bubble Up)
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
                // Correct position mil gayi → stop
                break;
            }
        }
    }

    // Print Heap
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

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap elements: ";
    h.print();

    return 0;
}