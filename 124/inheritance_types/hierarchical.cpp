// Hierarchical Inheritance
// opposite of multiple inheritance

#include <iostream>
using namespace std;

// Base class
class A
{
public:
    void showA()
    {
        cout << "Inside class A" << endl;
    }
};

// Derived class from A
class B : public A
{
public:
    void showB()
    {
        cout << "Inside class B" << endl;
    }
};

// Another derived class from A
class C : public A
{
public:
    void showC()
    {
        cout << "Inside class C" << endl;
    }
};

int main()
{
    B objB;
    C objC;

    cout << "Object of class B:" << endl;
    objB.showA(); // from A
    objB.showB(); // from B

    cout << "\nObject of class C:" << endl;
    objC.showA(); // from A
    objC.showC(); // from C

    return 0;
}

// Object of class B:
// Inside class A
// Inside class B

// Object of class C:
// Inside class A
// Inside class C
