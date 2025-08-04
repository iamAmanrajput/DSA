#include <iostream>
using namespace std;

// Inline function definition
// Compiler is requested to replace function call with actual function code
inline void numberShow(int num)
{
    // Prints the number followed by a newline
    cout << num << endl;
}

int main()
{
    // Function called 20 times with value 10
    // Since it's inline, compiler may replace each call with: cout << 10 << endl;
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);

    return 0;
}
