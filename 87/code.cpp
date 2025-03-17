// double pointer

#include <iostream>
using namespace std;

void solve(int **p)
{
    // ptr = ptr + 1
    //*ptr = *ptr + 1

    **p = **p + 1;
}

int main()
{

    int a = 5;
    int *p = &a;
    int **q = &p;

    cout << "before value of a is " << a << endl;

    solve(q);

    cout << "after value of a is " << a << endl;

    return 0;
}

// output
// before value of a is 5
// after value of a is 6