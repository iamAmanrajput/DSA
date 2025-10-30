// Destructor Releasing Heap Memory

#include <iostream>
using namespace std;

class Student
{
private:
    int *marks; // dynamically allocated memory

public:
    // Constructor
    Student(int m)
    {
        marks = new int; // memory allocate
        *marks = m;
        cout << "Constructor: Marks allocated -> " << *marks << endl;
    }

    // Destructor
    ~Student()
    {
        delete marks; // memory free
        cout << "Destructor: Memory released ✅" << endl;
    }

    void show()
    {
        cout << "Marks: " << *marks << endl;
    }
};

int main()
{
    Student s1(95);
    s1.show();
    return 0;
}

// Constructor: Marks allocated -> 95
// Marks: 95
// Destructor: Memory released
