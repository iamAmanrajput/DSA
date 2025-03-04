// string to integer [atoi] -- (LC)

#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

// Function to convert a string to an integer (similar to atoi function)
int myAtoi(string s)
{
    int num = 0, i = 0, sign = 1; // num stores the final number, sign handles negative values

    // Ignore leading whitespaces
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }

    // Check for sign (+ or -)
    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '+') ? 1 : -1; // If '-' is found, sign = -1
        i++;
    }

    // Convert characters to integer
    while (i < s.size() && isdigit(s[i]))
    {
        // Handle integer overflow
        if (num > (INT_MAX / 10) || (num == INT_MAX / 10 && s[i] > '7'))
        {
            return (sign == 1) ? INT_MAX : INT_MIN; // Return max/min limit
        }

        num = num * 10 + (s[i] - '0'); // Convert character to integer
        i++;
    }

    return num * sign; // Multiply final number with sign (+ve or -ve)
}

int main()
{
    string s;

    // Taking good input example: "   -456"
    cout << "Enter a string: ";
    getline(cin, s); // Using getline to take full input including spaces

    // Calling function to convert string to integer
    int result = myAtoi(s);

    // Output the converted integer
    cout << "Converted Integer: " << result << endl;

    return 0;
}

// input
//  Enter a string:      -123hello

// output
//  Converted Integer: -123