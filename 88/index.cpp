// Optimizing Sieve of Erathosthenes

#include <iostream>
#include <vector>
using namespace std;

vector<bool> Sieve(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
        {

            int j = i * i; // optimization 1
            // first unmarked number would be i*i, as others have been marked by 2 to (i-1)
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

int main()
{
    vector<bool> sieve = Sieve(25);

    for (int i = 0; i <= 25; i++)
    {
        if (sieve[i])
        {
            cout << i << ' ';
        }
    }

    return 0;
}

// output
// 2 3 5 7 11 13 17 19 23