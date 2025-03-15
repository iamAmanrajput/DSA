// Better Method TC -> O(log b)

#include <iostream>
using namespace std;

int main()
{

    int a = 5;
    int b = 4;
    int ans = 1;

    while (b > 0)
    {
        if (b & 1)
        { // condition says b is odd
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1; // divide by 2
    }

    cout << ans;

    return 0;
}

// output
// 625