// Palindromic Substrings (LC)

#include <iostream>
#include <string>

using namespace std;

/**
 * Function to expand around a given index and count palindromic substrings.
 * param s - Input string.
 * param i - Left index.
 * param j - Right index.
 * return - Count of palindromic substrings found in this expansion.
 */
int expandAroundIndex(string s, int i, int j)
{
    int count = 0;

    // Expand while characters at i and j are equal and within bounds
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++; // Found a palindrome
        i--;     // Expand left
        j++;     // Expand right
    }

    return count;
}

/**
 * Function to count all palindromic substrings in a given string.
 * param s - Input string.
 * return - Total number of palindromic substrings.
 */
int countSubstrings(string s)
{
    int count = 0;

    // Iterate through each character as a potential center of palindrome
    for (int i = 0; i < s.length(); i++)
    {
        // Count odd-length palindromes (single center)
        int oddAns = expandAroundIndex(s, i, i);
        count += oddAns;

        // Count even-length palindromes (double center)
        int evenAns = expandAroundIndex(s, i, i + 1);
        count += evenAns;
    }

    return count;
}

int main()
{
    string s;

    // Taking input from the user
    cout << "Enter the string: ";
    cin >> s;

    // Finding and printing the count of palindromic substrings
    int result = countSubstrings(s);
    cout << "Total palindromic substrings: " << result << endl;

    return 0;
}
