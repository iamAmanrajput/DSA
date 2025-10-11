// optimized Segmented Sieve

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Normal Sieve of Eratosthenes to get primes up to n
vector<bool> Sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

// Segmented Sieve from L to R
vector<bool> segSieve(int L, int R)
{
    int limit = sqrt(R);
    vector<bool> sieve = Sieve(limit);

    vector<int> basePrimes;
    for (int i = 2; i <= limit; i++)
    {
        if (sieve[i])
            basePrimes.push_back(i);
    }

    vector<bool> isPrime(R - L + 1, true);

    if (L == 0)
    {
        isPrime[0] = false;
        if (R >= 1)
            isPrime[1 - L] = false;
    }
    if (L == 1)
        isPrime[0] = false;

    for (int prime : basePrimes)
    {
        // Find the first multiple of prime in [L, R]
        int start = max(prime * prime, ((L + prime - 1) / prime) * prime);

        for (int j = start; j <= R; j += prime)
        {
            isPrime[j - L] = false;
        }
    }

    return isPrime;
}

int main()
{
    int L = 10, R = 50;
    vector<bool> primes = segSieve(L, R);

    cout << "Primes between " << L << " and " << R << ":\n";
    for (int i = 0; i <= R - L; i++)
    {
        if (primes[i])
            cout << i + L << " ";
    }
    cout << endl;

    return 0;
}
