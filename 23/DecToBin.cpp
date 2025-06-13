// DECIMAL TO BINARY USING BINARY SHIFT METHOD

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n = 10;
    int i = 0;
    int binNum = 0;

    while (n > 0)
    {
        int bit = n & 1;
        binNum = bit * pow(10, i++) + binNum;
        n = n >> 1;
    }
    cout << binNum << endl;

    return 0;
}

// output
// 1010