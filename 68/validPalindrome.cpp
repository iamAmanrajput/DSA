// Valid palindrome II  (LC)

#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s, int start, int end)
{ // check palindrome or not
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {
        if (s[start] != s[end])
        { // ya to start wala remove hoke palindrome banega ya phir end wala remove hoke
            return checkPalindrome(s, start + 1, end) || checkPalindrome(s, start, end - 1);
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (validPalindrome(s))
    {
        cout << "Yes, it is a valid palindrome after at most one deletion." << endl;
    }
    else
    {
        cout << "No, it is not a valid palindrome." << endl;
    }

    return 0;
}
