#include <iostream>
using namespace std;
// Dynamic memory Allocation

class Animal
{
private:
    int weight;

public:
    // state or Properties
    int age;
    string name;

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
    // Dynamic
    Animal *Suresh = new Animal;

    (*Suresh).age = 18;
    (*Suresh).name = "dogesh";

    // Alternative way
    Suresh->age = 20;
    Suresh->name = "kingPin";

    return 0;
}
