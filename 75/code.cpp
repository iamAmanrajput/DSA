// reorganize string (LC)

#include <iostream>
#include <limits.h>
#include <string>
using namespace std;

// Function to reorganize the string such that no two adjacent characters are the same
string reorganizeString(string s)
{
    int hash[26] = {0}; // Frequency array for characters

    // Count frequency of each character
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    // Find the most frequent character
    char most_freq_char;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            most_freq_char = i + 'a'; // Convert index to character
        }
    }

    // Try placing the most frequent character at even indices first
    int index = 0;
    while (max_freq > 0 && index < s.size())
    {
        s[index] = most_freq_char;
        max_freq--;
        index += 2;
    }

    // If we cannot place all occurrences of the most frequent character, return ""
    if (max_freq != 0)
    {
        return "";
    }

    // Mark the most frequent character as used
    hash[most_freq_char - 'a'] = 0;

    // Place the remaining characters
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            // If index goes out of bounds, start filling from odd indices
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }

    return s; // Return the reorganized string
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = reorganizeString(s);

    if (result == "")
    {
        cout << "The string cannot be reorganized to meet the conditions.\n";
    }
    else
    {
        cout << "Reorganized String: " << result << endl;
    }

    return 0;
}

// input
//  Enter a string: aaabebbfgg

// output
// Reorganized String: abaeafbgbg