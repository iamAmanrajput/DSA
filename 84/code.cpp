#include <iostream>
using namespace std;

int main()
{

    int a = 5;
    int *ptr = &a;

    cout << "Address of a is using ptr : " << ptr << endl;
    cout << "Address of a is using &a : " << &a << endl;
    cout << "value of a is using a : " << a << endl;
    cout << "value of a is using *ptr : " << *ptr << endl;
    cout << "Address of ptr is using &ptr : " << &ptr << endl;

    return 0;
}

// output
// Address of a is using ptr : 0x61ff0c
// Address of a is using &a : 0x61ff0c
// value of a is using a : 5
// value of a is using *ptr : 5
// Address of ptr is using &ptr : 0x61ff08