// finding maximum element in arr

#include <iostream>
#include <climits>
using namespace std;

void findMax(int arr[], int n, int i, int &maxi)
{
    if (n <= i)
    {
        return;
    }
    if (arr[i] > maxi)
    {
        maxi = arr[i];
    }

    findMax(arr, n, i + 1, maxi);
}

int main()
{
    int arr[5] = {10, 50, 20, 100, 80};
    int n = 5;
    int maxi = INT_MIN;
    int i = 0;
    findMax(arr, n, i, maxi);
    cout << "Maxium number is " << maxi;

    return 0;
}

// output
//  Maxium number is 100
