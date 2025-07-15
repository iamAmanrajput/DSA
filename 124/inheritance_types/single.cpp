// Single Inheritance

#include <iostream>
using namespace std;

// Base class
class Vehicle
{
public:
    void start()
    {
        cout << "Vehicle is starting..." << endl;
    }
};

// Derived class (single inheritance)
class Car : public Vehicle
{
public:
    void drive()
    {
        cout << "Car is driving..." << endl;
    }
};

int main()
{
    Car myCar;

    myCar.start(); // Inherited from Vehicle
    myCar.drive(); // Own method of Car

    return 0;
}
