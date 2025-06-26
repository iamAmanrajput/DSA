// find missing element from array with duplicate -- (GFG)
// # Visited Method
#include <iostream>
using namespace std;

int main()
{

    int arr[5] = {1, 3, 5, 3, 4};

    int duplicate = -1;

    for (int i = 0; i < 5; i++)
    {

        int element = abs(arr[i]);

        if (arr[element - 1] < 0)
        {
            duplicate = element;
        }

        if (arr[element - 1] > 0)
        {
            arr[element - 1] *= -1;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > 0)
        {
            cout << "Duplicate: " << duplicate << endl;
            cout << "Missing: " << i + 1 << endl;
            break;
        }
    }

    return 0;
}