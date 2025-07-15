#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
    void eat()
    {
        cout << "This animal eats food." << endl;
    }
};

// Derived class
class Dog : public Animal
{
public:
    void bark()
    {
        cout << "The dog barks." << endl;
    }
};

int main()
{
    Dog d;

    d.eat();  // Inherited from Animal
    d.bark(); // Own method of Dog

    return 0;
}
