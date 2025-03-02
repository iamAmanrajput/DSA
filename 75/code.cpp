// reorganize string (LC)

#include <iostream>
#include <climits>
using namespace std;

// Function to reorganize the string
string reorganizeString(string s)
{
    int hash[26] = {0}; // Character frequency count store karne ke liye

    // Step 1: Count frequency of each character
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++; // Example: "aab" ke liye hash['a' - 'a']++ -> hash[0]++
    }

    // Step 2: Find the most frequent character
    char most_freq_char;
    int max_freq = INT_MIN;

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            most_freq_char = i + 'a'; // Index se character me convert karna
        }
    }

    // Step 3: Place the most frequent character first at even indices
    int index = 0;
    while (max_freq > 0 && index < s.size())
    {
        s[index] = most_freq_char;
        index += 2;
        max_freq--;
    }

    // Agar max_freq bacha hai, iska matlab placement possible nahi
    if (max_freq != 0)
    {
        return "";
    }

    // Step 4: Mark most frequent character as placed
    hash[most_freq_char - 'a'] = 0;

    // Step 5: Place the remaining characters
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            index += 2;
            hash[i]--;
        }
    }

    return s;
}

// Driver Code
int main()
{
    // Example 1
    string s1 = "aab";
    cout << "Input: " << s1 << " -> Output: " << reorganizeString(s1) << endl; // Expected: "aba"

    // Example 2
    string s2 = "aaab";
    cout << "Input: " << s2 << " -> Output: " << reorganizeString(s2) << endl; // Expected: ""

    // Example 3
    string s3 = "vvvlo";
    cout << "Input: " << s3 << " -> Output: " << reorganizeString(s3) << endl; // Expected: "vlvov"

    return 0;
}

// input
//  Enter a string: aaabebbfgg

// output
// Reorganized String: abaeafbgbg