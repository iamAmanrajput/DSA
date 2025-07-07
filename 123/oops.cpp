#include <iostream>
using namespace std;
// static memory Allocation

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
    void setWeight(int w)
    {
        weight = w;
    }
};

int main()
{
    // static
    Animal ramesh;
    ramesh.age = 12;
    ramesh.name = "dogesh";
    cout << "age of ramesh dog is : " << ramesh.age << endl;
    cout << "name of ramesh dog is : " << ramesh.name << endl;
    ramesh.eat();
    // cout << "weight of ramesh dog is : " << ramesh.weight << endl; // because this is private , we can't access directly

    // setting weight value using setter
    ramesh.setWeight(100);

    // getting weight value using getter
    cout << "weight of ramesh dog is : " << ramesh.getWeight() << endl;

    return 0;
}

// age of ramesh dog is : 12
// name of ramesh dog is : dogesh
// Eating
// weight of ramesh dog is : 100