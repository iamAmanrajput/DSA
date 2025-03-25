// Sort 0's and 1's

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{0, 1, 0, 1, 1, 0, 1, 0, 1, 1};
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) // Use <= to ensure all elements are processed
    {
        if (arr[start] == 0)
        {
            start++; // Move forward if the element is already 0
        }
        else
        {
            swap(arr[start], arr[end]); // Swap 1 with the element at the end
            end--;                      // Decrement the end pointer
        }
    }

    // Print the sorted array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}