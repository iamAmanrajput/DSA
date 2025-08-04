// Friend Keyword
#include <iostream>
using namespace std;

// Class A
class A
{
private:
    int x; // Private data member

public:
    // Constructor to initialize x
    A(int _val) : x(_val) {}

    // Getter function to access x
    int getX() const { return x; }

    // Setter function to modify x
    void setX(int _val) { x = _val; }

    // Declaring class B as a friend of A
    // So B can access private members of A directly
    friend class B;

    // Declaring function print() as a friend of A
    // So it can also access private members directly
    friend void print(const A &);
};

// Friend function (not part of any class)
void print(const A &a)
{
    // Accessing private member x of class A directly
    cout << "Friend function print(): " << a.x << endl;
}

// Friend class B
class B
{
public:
    // Member function of class B
    void print(const A &a)
    {
        // Accessing private member x of class A directly
        // Because class B is a friend of class A
        cout << "Friend class B printing: " << a.x << endl;
    }
};

int main()
{
    A a(5);     // Create object of class A and initialize x = 5
    B b;        // Create object of class B
    b.print(a); // Friend class B accessing private member
    print(a);   // Friend function accessing private member
    return 0;
}

// Output
// Friend class B printing: 5
// Friend function print(): 5
