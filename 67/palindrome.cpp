// check palindrome or not

#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char arr[])
{
    int start = 0;
    int end = strlen(arr) - 1;

    while (start <= end)
    {
        if (arr[start] != arr[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    char arr[100];

    cout << "Enter a string: ";
    cin >> arr;

    if (isPalindrome(arr))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}

// input
//  Enter a string: madam

// output
// palindrome