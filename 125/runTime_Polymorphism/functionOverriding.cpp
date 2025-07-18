// Function Overriding

#include <iostream>
using namespace std;

class Animal
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    // override
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    Animal a;
    a.speak();

    Dog b;
    b.speak();

    return 0;
}

// output
// Speaking
// Barking