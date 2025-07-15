// Example to solve Ambiguity

#include <iostream>
using namespace std;

class A
{
public:
    int chemistry;
    A()
    {
        chemistry = 10;
    }
};

class B
{
public:
    int chemistry;
    B()
    {
        chemistry = 20;
    }
};

class C : public A, public B
{
public:
    int math;
};

int main()
{
    C obj;
    cout << " " << obj.A::chemistry; // 10

    return 0;
}

// 10 because we solve the ambiguity using scope resolution operator