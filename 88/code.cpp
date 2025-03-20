// optimized Segmented Sieve

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<bool> segSieve(int L, int R)
{
    // get me prime array , i will use it to mark seg sieve
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basPrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basPrimes.push_back(i);
        }
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 1 || L == 0)
    {
        segSieve[L] = false;
    }
}

int main()
{

    return 0;
}