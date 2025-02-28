// Valid Anagram (LC)

#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    int frequencyTable[256] = {0};

    for (char c : s)
        frequencyTable[c]++;
    for (char c : t)
        frequencyTable[c]--;

    for (int i = 0; i < 256; i++)
    {
        if (frequencyTable[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}

// input
//  Enter first string: anagram
//  Enter second string: nagaram

// output
//  The strings are anagrams.