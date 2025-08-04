#include <iostream>
#include "bird.h"
using namespace std;

// Function that accepts a pointer to Bird and calls its methods
void birdDoesSomething(Bird *bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
}

int main()
{
    Bird *bird = new Sparrow(); // Pointer of base class pointing to derived class object (Polymorphism)
    birdDoesSomething(bird);

    delete bird; // Always free heap memory

    // Bird *b2 = new Bird(); // it throws error because we cannot create instance of iterface
    return 0;
}

// Output
// Sparrow is eating
// Sparrow is flying
// Sparrow is eating