// Q - Can Constructor be Made Prvate ?
// yes

#include <iostream>
using namespace std;

// Box class with private constructor
class Box
{
    int width; // width is private by default

    // ✅ Private Constructor — Direct object creation from outside is not allowed
    Box(int _w) : width(_w) {};

public:
    // Getter function to return the width
    int getWidth() const
    {
        return width;
    }

    // Setter function to modify the width
    void setWidth(int _val)
    {
        width = _val;
    }

    // ✅ Declaring BoxFactory as a friend class
    // So it can access private constructor and create Box objects
    friend class BoxFactory;
};

// Factory class to create Box objects
class BoxFactory
{
    int count; // (optional) to keep track of how many boxes were created

public:
    // Function to create and return a Box object
    Box getABox(int _w)
    {
        ++count;        // Increase count when new box is created
        return Box(_w); // ✅ Accessing private constructor of Box
    }
};

int main()
{
    BoxFactory bFact;             // Create object of BoxFactory
    Box b = bFact.getABox(10);    // Create Box using factory
    cout << b.getWidth() << endl; // Print width of Box → Output: 10
    return 0;
}
