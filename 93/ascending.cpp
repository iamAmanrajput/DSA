// Check whether the array is in ascending order or not.

#include <iostream>
using namespace std;

bool checkAscending(int arr[], int size, int index)
{
    if (index == size - 1) // Last element tak pahunch gaye, iska matlab array ascending hai
    {
        return true;
    }

    if (arr[index] > arr[index + 1]) // Agar koi bhi element agle se bada hai, toh false return karein
    {
        return false;
    }

    return checkAscending(arr, size, index + 1);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Change this array to test different cases
    int index = 0;

    bool ans = checkAscending(arr, 5, index);

    if (ans)
    {
        cout << "Yes, this is an ascending order array.";
    }
    else
    {
        cout << "No, this is not in ascending order.";
    }

    return 0;
}
