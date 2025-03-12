// Behaviour for char array

#include <iostream>
using namespace std;

int main()
{

    char ch[10] = "Aman";

    char *c = ch;

    cout << c << endl;
    cout << *c << endl;

    return 0;
}

// output
// Aman
// A