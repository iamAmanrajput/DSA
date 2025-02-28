// RReverse Only Letters

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAlphabet(char w)
    {
        return ((w >= 'A' && w <= 'Z') || (w >= 'a' && w <= 'z'));
    }

    string reverseOnlyLetters(string s)
    {
        int start = 0, end = s.size() - 1;

        while (start < end)
        {
            if (!isAlphabet(s[start]))
            {
                start++;
            }
            else if (!isAlphabet(s[end]))
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
};

int main()
{
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Reversed only letters: " << sol.reverseOnlyLetters(s) << endl;

    return 0;
}

// input
//  Enter a string: a-bc-dEf-dcba
// output
//  Reversed only letters: a-bc-dfE-dcba