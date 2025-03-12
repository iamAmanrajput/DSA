// Behaviour for char array

#include <iostream>
using namespace std;

int main()
{

    char ch[10] = "Aman";

    char *c = ch;

    cout << c << endl;  // ch[0] ka address print hona chahiye tha but puri string print ho gyi
    cout << *c << endl; // first char print hoga

    cout << ch << endl;
    cout << &ch << endl;
    cout << ch[0] << endl;
    cout << &c << endl;

    return 0;
}

// output
// Aman
// A

// Aman
// 0x61ff06
// A
// 0x61ff00