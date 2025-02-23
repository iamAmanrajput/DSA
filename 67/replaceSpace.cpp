// Replace Space with @

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{

    char arr[100];

    cin.getline(arr, 100);

    int n = strlen(arr);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ' ')
        {
            arr[i] = '@';
        }
    }

    cout << arr;

    return 0;
}

// input
//  my name is aman singh

// output
//  my@name@is@aman@singh