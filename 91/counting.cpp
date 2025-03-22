// reverse counting using rrecursion

#include <iostream>
using namespace std;

void counting(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    counting(n - 1);
}

int main()
{

    int n;
    cout << "Enter the value of n " << endl;
    cin >> n;

    counting(n);

    return 0;
}

// input/output
//  Enter the value of n
//  10
//  10 9 8 7 6 5 4 3 2 1