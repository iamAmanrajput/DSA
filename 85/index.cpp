// pointers with function

#include <iostream>
using namespace std;

void solve(int arr[])
{
    cout << "Printing the size of arr inside sum " << sizeof(arr) << endl;

    cout << "arr : " << arr << endl;   // ye to main wale ka arr address hi store karega
    cout << "&arr : " << &arr << endl; // eska alag se khudka address hoga
}

int main()
{

    int arr[10] = {1, 2, 3, 4};
    cout << "Printing the size of arr inside main " << sizeof(arr) << endl;

    cout << arr << endl;
    cout << &arr << endl;

    solve(arr);

    return 0;
}

// output

// Printing the size of arr inside main40
// 0x61fee8
// 0x61fee8
// Printing the size of arr inside sum4
// arr : 0x61fee8
// &arr : 0x61fed0