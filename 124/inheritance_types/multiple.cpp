// Multiple Inheritance

#include <iostream>
using namespace std;

// First base class
class A
{
public:
    void showA()
    {
        cout << "Inside class A" << endl;
    }
};

// Second base class
class B
{
public:
    void showB()
    {
        cout << "Inside class B" << endl;
    }
};

// Derived class from A and B
class C : public A, public B
{
public:
    void showC()
    {
        cout << "Inside class C" << endl;
    }
};

int main()
{
    C obj;

    obj.showA(); // From class A
    obj.showB(); // From class B
    obj.showC(); // From class C

    return 0;
}

// Inside class A
// Inside class B
// Inside class C
