// check palindrome using recursion

#include <iostream>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    // base case
    if (start >= end)
    {
        return true;
    }

    if (s[start] != s[end])
    {
        return false;
    }
    return isPalindrome(s, start + 1, end - 1);
}

int main()
{
    string s = "madam";

    if (isPalindrome(s, 0, s.size() - 1))
    {
        cout << "Yes It is Plaindrome";
    }
    else
    {
        cout << "No It is Not a Palindrome";
    }

    return 0;
}

// output
//  Yes It is Plaindrome
