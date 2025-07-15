// MultiLevel Inheritance
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

// Derived from A
class B : public A
{
public:
    void showB()
    {
        cout << "Inside class B" << endl;
    }
};

// Derived from B
class C : public B
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
