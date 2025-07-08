#include <iostream>
using namespace std;
// Constructor

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
};

int main()
{
    Animal a(10);
    Animal *b = new Animal;

    // object copy
    Animal c = a;

    // second way
    // Animal animal1(c);

    return 0;
}

// Parametrized constructor called
// Constructor Called
// I am Inside Copy Constructor
