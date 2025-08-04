#ifndef BIRD_H
#define BIRD_H

#include <iostream>
using namespace std;

// Abstract base class
// Interface
class Bird
{
public:
    // Pure virtual functions
    virtual void eat() = 0;
    virtual void fly() = 0;

    // Note: Any class inheriting Bird must implement both eat() and fly()
};

// Derived class that implements the pure virtual functions
// Implementation
class Sparrow : public Bird
{
public:
    void eat() override
    {
        cout << "Sparrow is eating\n";
    }

    void fly() override
    {
        cout << "Sparrow is flying\n";
    }
};

class Eagle : public Bird
{
public:
    void eat() override
    {
        cout << "Eagle is eating\n";
    }

    void fly() override
    {
        cout << "Eagle is flying\n";
    }
};

#endif // BIRD_H
