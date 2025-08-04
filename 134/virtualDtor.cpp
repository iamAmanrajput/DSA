// Q - Can we make virtual Destructor ?
// ✅ Yes, destructors **can** and **should** be virtual in base classes

#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Constructor
    Base()
    {
        cout << "Base ctor\n";
    }

    // ✅ Virtual Destructor ensures proper cleanup of derived class objects
    virtual ~Base()
    {
        cout << "Base dtor\n";
    }
};

// Derived class
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
    // Base class pointer pointing to Derived class object
    Base *b = new Derived();

    // Deleting object using base class pointer
    // If base destructor is **not virtual**, only Base's destructor will be called (memory leak risk)
    // If base destructor is **virtual**, both Derived and Base destructors will be called
    delete b;

    return 0;
}

/*
Output when Base class destructor is NOT virtual:
Base ctor
Derived ctor
Base dtor
// ⚠️ Derived destructor is not called → potential memory/resource leak

Output when Base class destructor IS virtual:
Base ctor
Derived ctor
Derived dtor
Base dtor
// ✅ Proper destruction of both Derived and Base parts of the object
*/
