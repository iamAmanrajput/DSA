// static data members
#include <iostream>
using namespace std;

class abc
{
public:
    // Static data members shared by all objects
    static int x, y;

    // Member function to print static variables
    void print() const
    {
        cout << x << " " << y << endl;
    }
};

// Static members must be defined outside the class
int abc::x;
int abc::y;

int main()
{
    abc obj1;
    obj1.x = 1;   // x = 1
    obj1.y = 2;   // y = 2
    obj1.print(); // Prints: 1 2

    abc obj2;
    obj2.x = 10;  // x = 10 (shared static variable)
    obj2.y = 20;  // y = 20 (shared static variable)
    obj1.print(); // Prints: 10 20 (because x, y are shared)
    obj2.print(); // Prints: 10 20

    return 0;
}
