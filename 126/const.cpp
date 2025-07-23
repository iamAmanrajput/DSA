#include <iostream>
using namespace std;

int main()
{

    // 1
    // const int x = 5; // x is constant
    // cout << x;

    // -----------------------------------------------------------------------------

    // 2 const with pointers
    // const data, non-const pointer
    const int *a = new int(2);
    // int const *a = new int(2); --second way to write
    cout << *a << endl;
    // *a = 20; // throws the error bcz we can't change the data(content) of pointer

    int b = 20;
    a = &b; // we can reassign the address of a but cant reassign the value of *a
    cout << *a << endl;
    // output
    //  2
    //  20

    // ---------------------------------------------------------------------------------

    // 3 const with pointers
    // const pointer, but non-const data
    int *const c = new int(2);
    cout << *c << endl;
    *c = 20; // we can change the data(content)
    cout << *c << endl;
    // output
    // 2
    // 20

    int b = 50;
    a = &b; // we can't do because pointer is constant

    // -------------------------------------------------------------------------------------

    // 4 const with pointers
    // const pointer , const data
    const int *const a = new int(10);
    cout << *a << endl;
    // *a = 30; // throw error
    // int b = 10;
    // a = &b; // throw error

    return 0;
}