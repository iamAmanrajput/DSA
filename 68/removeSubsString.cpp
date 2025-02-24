// remove all occurance of a substring (LC)

#include <iostream>
#include <string>
using namespace std;

// Function to remove all occurrences of 'part' from 's'
string removeOccurrences(string s, string part)
{
    int pos = s.find(part);

    while (pos != string::npos)
    { // Keep removing while part exists
        s.erase(pos, part.length());
        pos = s.find(part);
    }

    return s; // Return the modified string
}

int main()
{
    // Test Cases
    string str1 = "daabcbaabcbc";
    string part1 = "abc";
    cout << "Input: " << str1 << ", Remove: " << part1
         << " -> Output: " << removeOccurrences(str1, part1) << endl;

    string str2 = "axxxxyyyyb";
    string part2 = "xy";
    cout << "Input: " << str2 << ", Remove: " << part2
         << " -> Output: " << removeOccurrences(str2, part2) << endl;

    string str3 = "aaaaaa";
    string part3 = "aa";
    cout << "Input: " << str3 << ", Remove: " << part3
         << " -> Output: " << removeOccurrences(str3, part3) << endl;

    return 0;
}
