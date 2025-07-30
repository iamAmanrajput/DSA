// Deep Copy
#include <iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    // Parameterized constructor
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // Deep copy constructor
    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y); // New memory allocate karke value copy karte hain
    }

    // Destructor to free allocated memory
    ~abc()
    {
        delete y;
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
    cout << "Printing a:" << endl;
    a.print();

    abc b = a; // Deep copy constructor call hota hai
    cout << "Printing b (after deep copy):" << endl;
    b.print();

    // Ab b ke pointer ke andar value change karte hain
    *b.y = 20;

    cout << "After modifying b's *y to 20:" << endl;

    cout << "Printing b:" << endl;
    b.print();

    cout << "Printing a (should be unchanged):" << endl;
    a.print();

    return 0;
}

// Output
// Printing a:
// X : 1
// PTR Y : 0x1141848
// Content of Y (*y) : 2

// Printing b (after deep copy):
// X : 1
// PTR Y : 0x1141858
// Content of Y (*y) : 2

// After modifying b's *y to 20:
// Printing b:
// X : 1
// PTR Y : 0x1141858
// Content of Y (*y) : 20

// Printing a (should be unchanged):
// X : 1
// PTR Y : 0x1141848
// Content of Y (*y) : 2
