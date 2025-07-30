// Shallow copy

#include <iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // default dumb copy constructor : it does shallow copy
    abc(const abc &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    void print() const
    {
        cout << "X : " << x << endl;
        cout << "PTR Y : " << y << endl;
        cout << "Content of Y (*y) : " << *y << endl
             << endl;
    }
};

int main()
{
    abc a(1, 2);
    cout << "Printint a\n";
    a.print();
    // output
    //     X : 1
    // PTR Y : 0x1091848
    // Content of Y (*y) : 2

    // abc b(a);  // Alternate way to call copy constructor
    abc b = a; // call copy constructor
    cout << "Printint b\n";
    b.print();
    // output
    //     X : 1
    // PTR Y : 0x1061848 // pointers are same so y of both a and b points the same address
    // Content of Y (*y) : 2

    *b.y = 20;
    cout << "Printint b\n";
    b.print();
    // output
    //     X : 1
    // PTR Y : 0x1061848 // pointers are same
    // Content of Y (*y) : 20

    cout << "Printint a\n";
    a.print();
    // output
    //     X : 1
    // PTR Y : 0x1061848 // pointers are same
    // Content of Y (*y) : 20
    return 0;
}
