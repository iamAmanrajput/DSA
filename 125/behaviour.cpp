// inheritance behaviour in upcasting and downcasting
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "I am inside Animal constructor" << endl;
    }
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "I am inside Dog constructor" << endl;
    }
    // override
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    Dog *a = (Dog *)new Animal();
    return 0;
}

// CASE - 1

// inheritance behaviour - deriverd class always call firstly base class constructor
// Dog *a = new Dog();
// I am inside Animal constructor
// I am inside Dog constructor

// CASE - 2

// inheritance behaviour - deriverd class always call firstly base class constructor
// Animal *a = new Dog();
// I am inside Animal constructor
// I am inside Dog constructor

// CASE - 3

// bcz right side me animal ka object banaya hai to animal to kisi pe depend nhi hai esliye sirf animal
// Dog *a = (Dog *)new Animal();
// I am inside Animal constructor