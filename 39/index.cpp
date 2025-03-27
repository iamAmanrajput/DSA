// Reverse integer -- (LC)

#include <iostream>
#include <climits>
using namespace std;

int reverse(int x)
{
    int reversed = 0; // Using int instead of long to strictly check 32-bit overflow

    while (x != 0)
    {
        int last_digit = x % 10;

        // Check if reversed will overflow before multiplying by 10
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && last_digit > 7))
        {
            return 0; // Overflow case for positive numbers
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && last_digit < -8))
        {
            return 0; // Overflow case for negative numbers
        }

        reversed = reversed * 10 + last_digit;
        x /= 10;
    }

    return reversed;
}

int main()
{
    int x = 123;
    cout << "Reversed: " << reverse(x) << endl;

    x = -123;
    cout << "Reversed: " << reverse(x) << endl;

    x = 1534236469; // Edge case: should return 0 due to overflow
    cout << "Reversed: " << reverse(x) << endl;

    return 0;
}
