// shallow copy
#include <iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    // Parameterized constructor - memory allocate karta hai y ke liye
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // Copy constructor - shallow copy karta hai, i.e. pointer ko copy karta hai
    abc(const abc &obj)
    {
        x = obj.x;
        y = obj.y; // Pointer copy hua, dono objects same memory ko point karenge
    }

    void print() const
    {
        cout << "X : " << x << endl;
        cout << "PTR Y : " << y << endl;
        cout << "Content of Y (*y) : " << *y << endl
             << endl;
    }

    // Destructor (shallow copy me double delete problem ho sakti hai)
    ~abc()
    {
        // Destructor me delete y karna dangerous ho sakta hai shallow copy ki wajah se
        // isliye yahan delete nahi kar rahe hain, par real scenario me careful handling chahiye
    }
};

int main()
{
    abc a(1, 2);
    cout << "Printing a\n";
    a.print();

    abc b = a; // copy constructor call hoga (shallow copy)
    cout << "Printing b\n";
    b.print();

    *b.y = 20;

    cout << "After modifying *b.y = 20\n";

    cout << "Printing b\n";
    b.print();

    cout << "Printing a\n";
    a.print();

    return 0;
}

// output
// Printing a
// X : 1
// PTR Y : 0x1021848
// Content of Y (*y) : 2

// Printing b
// X : 1
// PTR Y : 0x1021848
// Content of Y (*y) : 2

// After modifying *b.y = 20
// Printing b
// X : 1
// PTR Y : 0x1021848
// Content of Y (*y) : 20

// Printing a
// X : 1
// PTR Y : 0x1021848
// Content of Y (*y) : 20