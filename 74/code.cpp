// Isomorphic Strings

#include <iostream>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }

    int hash[255] = {0};      // s[i] -> t[i] mapping ke liye
    bool isMapped[255] = {0}; // Check karne ke liye ki t[i] kisi aur se pehle map to nahi hua

    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] == 0 && isMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];     // `s[i]` ko `t[i]` se map karo
            isMapped[t[i]] = true; // `t[i]` map ho chuka hai
        }
    }

    // Check if mapping is valid
    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] != t[i])
        {
            return false;
        }
    }

    return true;
}

// Driver Code
int main()
{
    // Example Cases
    cout << isIsomorphic("egg", "add") << endl;     // Output: 1 (true)
    cout << isIsomorphic("foo", "bar") << endl;     // Output: 0 (false)
    cout << isIsomorphic("paper", "title") << endl; // Output: 1 (true)
    cout << isIsomorphic("ab", "aa") << endl;       // Output: 0 (false)

    return 0;
}

// output

// 1
// 0
// 1
// 0
