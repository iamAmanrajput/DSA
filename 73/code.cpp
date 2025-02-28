// reverse vowels of a string

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

string reverseVowels(string s)
{
    int start = 0, end = s.length() - 1;
    while (start <= end)
    {
        if (!isVowel(s[start]))
        {
            start++;
        }
        else if (!isVowel(s[end]))
        {
            end--;
        }
        else
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    return s;
}

int main()
{
    string str = "IceCreAm";
    cout << reverseVowels(str) << endl;

    str = "leetcode";
    cout << reverseVowels(str) << endl; // Output: leotcede

    return 0;
}

// output

// AceCreIm
// leotcede
