// finding prime number using Naive Approch
// # Naive Approach O(n^2);

class Solution
{
public:
    bool checkPrime(int num)
    {
        for (int i = 2; i < num; i++)
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