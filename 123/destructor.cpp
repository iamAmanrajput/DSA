#include <iostream>
using namespace std;
// Destructor

class Animal
{
private:
    int weight;

public:
    // state or Properties
    int age;
    string name;

    // Default Constructor
    Animal()
    {
        this->age = 0;
        this->weight = 0;
        this->name = "";
        cout << "Constructor Called" << endl;
    }

    // Parametrized Constructor
    Animal(int age)
    {
        this->age = age;
        cout << "Parametrized constructor called" << endl;
    }

    // Copy Constructor
    Animal(Animal &obj)
    {
        this->age = obj.age;
        this->weight = obj.weight;
        this->name = obj.name;
        cout << "I am Inside Copy Constructor" << endl;
    }

    // Behaviour
    void eat()
    {
        cout << "Eating" << endl;
    }

    void sleep()
    {
        cout << "Sleeping" << endl;
    }

    // getter
    int getWeight()
    {
        return weight;
    }

    // setter
    void setWeight(int weight)
    {
        this->weight = weight;
    }

    ~Animal()
    {
        cout << "I am Inside Destructor" << endl;
    }
};

int main()
{
    // Animal a;
    // a.age = 5;

    Animal *b = new Animal();
    b->age = 12;
    // manually calling destructor
    delete b;

    return 0;
}

// for static memory allocation
// Constructor Called
// I am Inside Destructor

// for dynamic memory allocation
// Constructor Called
// I am Inside Destructor