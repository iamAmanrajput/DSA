// Hybrid Inheritance

#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "Inside class A" << endl;
    }
};

class B : virtual public A
{
public:
    void showB()
    {
        cout << "Inside class B" << endl;
    }
};

class C : virtual public A
{
public:
    void showC()
    {
        cout << "Inside class C" << endl;
    }
};

class D : public B, public C
{
public:
    void showD()
    {
        cout << "Inside class D" << endl;
    }
};

int main()
{
    D obj;
    obj.showA(); // From class A
    obj.showB(); // From class B
    obj.showC(); // From class C
    obj.showD(); // From class D

    return 0;
}
