// function overloading
#include <iostream>
using namespace std;

class Calculator
{
public:
    // Function with 2 int parameters
    void add(int a, int b)
    {
        cout << "Sum (int): " << a + b << endl;
    }

    // Function with 2 float parameters
    void add(float a, float b)
    {
        cout << "Sum (float): " << a + b << endl;
    }

    // Function with 3 int parameters
    void add(int a, int b, int c)
    {
        cout << "Sum (3 int): " << a + b + c << endl;
    }
};

int main()
{
    Calculator calc;

    calc.add(5, 10);      // Calls int version
    calc.add(3.5f, 2.5f); // Calls float version
    calc.add(1, 2, 3);    // Calls 3 int version

    return 0;
}
