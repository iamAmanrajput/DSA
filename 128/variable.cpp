// Global vs Local Variable

#include <iostream>
using namespace std;

// Global variable declaration
int x = 2; // GLOBAL VARIABLE

void fun()
{
    int x = 60;                                             // Local variable to fun()
    cout << "In fun() - Local x: " << x << endl;            // Prints local x of fun() (60)
    ::x = 40;                                               // Global x ko update kiya
    cout << "In fun() - Global x using :: " << ::x << endl; // Prints updated global x (40)
}

int main()
{
    ::x = 4;                                                 // Sets global x = 4
    int x = 20;                                              // Local to main()
    cout << "In main() - Local x: " << x << endl;            // Prints main ka local x (20)
    cout << "In main() - Global x using :: " << ::x << endl; // Prints global x (4)

    {
        int x = 50; // Local to this block
        {
            int x = 44;                                        // Local to this inner block
            cout << "In inner block - Local x: " << x << endl; // Prints 44
        }
        cout << "In block - Local x: " << x << endl;            // Prints 50
        cout << "In block - Global x using :: " << ::x << endl; // Prints global x (4)
    }

    fun(); // Call the function

    cout << "After fun() call:" << endl;
    cout << "In main() - Local x: " << x << endl;            // Prints main ka local x (20)
    cout << "In main() - Global x using :: " << ::x << endl; // Prints latest global x (40) after fun()

    return 0;
}

// output
// In main() - Local x: 20
// In main() - Global x using :: 4
// In inner block - Local x: 44
// In block - Local x: 50
// In block - Global x using :: 4
// In fun() - Local x: 60
// In fun() - Global x using :: 40
// After fun() call:
// In main() - Local x: 20
// In main() - Global x using :: 40