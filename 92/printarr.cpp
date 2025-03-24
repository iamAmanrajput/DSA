// printing array using recursion

#include <iostream>
using namespace std;

void printNum(int arr[], int size, int i)
{
    if (i >= size)
    {
        return;
    }
    cout << arr[i] << endl;

    printNum(arr, size, i + 1); // Recursive call
}

int main()
{
    int arr[5] = {10, 11, 12, 13, 14};
    int size = 5;
    int i = 0;
    printNum(arr, size, i);

    return 0;
}

// output
// 10
// 11
// 12
// 13
// 14
