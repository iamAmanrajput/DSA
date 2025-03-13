// finding prime number using Sqrt Approch
// # Naive Approach O(N∗Sqrt(N));

#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool checkPrime(int num)
    {
        int sqrtN = sqrt(num);
        for (int i = 2; i <= sqrtN; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
        {
            return 0;
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (checkPrime(i))
            {
                count++;
            }
        }
        return count;
    }
};