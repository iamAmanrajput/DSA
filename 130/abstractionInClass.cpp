// Abstraction in C++
#include <iostream>
using namespace std;

// Class that demonstrates abstraction
class AbstractionExample
{
private:
    int num; // Private data member - hidden from outside
    char ch; // Private data member - hidden from outside

public:
    // Public function to set values of private members
    void setMyValues(int n, char c)
    {
        num = n; // Assigning value to num
        ch = c;  // Assigning value to ch
    }

    // Public function to get (print) values of private members
    void getMyValues()
    {
        cout << "Numbers is: " << num << endl; // Printing value of num
        cout << "Char is: " << ch << endl;     // Printing value of ch
    }
};

/*
Key Points:
- The data members `num` and `ch` are private, so they are hidden from the outside world.
- They cannot be accessed directly from outside the class.
- To interact with these members, we provide public methods `setMyValues()` and `getMyValues()`.
- This is called **abstraction**: hiding internal details and showing only essential features.
*/
