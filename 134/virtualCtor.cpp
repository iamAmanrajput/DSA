// Q - Can we make virtual Constructor ?
// No, constructors cannot be virtual in C++

#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // ❌ Invalid: Constructor cannot be virtual in C++
    virtual Base() // ❌ This will cause a compilation error
    {
        cout << "Base ctor\n";
    }

    // Destructor (not virtual)
    ~Base()
    {
        cout << "Base dtor\n";
    }
};

// Derived class inheriting Base
class Derived : public Base
{
public:
    // Constructor
    Derived()
    {
        cout << "Derived ctor\n";
    }

    // Destructor
    ~Derived()
    {
        cout << "Derived dtor\n";
    }
};

int main()
{
    // Base class pointer pointing to Derived class object (Polymorphism)
    Base *b = new Derived();

    // Deleting the object using base class pointer
    delete b;

    return 0;
}
