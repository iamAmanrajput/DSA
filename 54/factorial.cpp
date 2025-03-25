// Factorial of Large Number

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num = 500; // Factorial of 5
    vector<int> ans;
    ans.push_back(1); // Initialize with 1
    int carry = 0;

    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x % 10; // Store the current digit
            carry = x / 10;  // Carry forward the rest
        }

        while (carry) // Handle remaining carry
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Print the result in reverse order
    reverse(ans.begin(), ans.end());
    for (int digit : ans)
    {
        cout << digit;
    }
    cout << endl;

    return 0;
}