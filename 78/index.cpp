// find the index of first occurance (LC)
// #sliding window approach

#include <iostream>
#include <string>
using namespace std;

// Function to find the index of the first occurrence of needle in haystack
int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (needle[j] != haystack[i + j])
            {
                break;
            }
            if (j == m - 1)
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    int result = strStr(haystack, needle); // Function call
    cout << "Output: " << result << std::endl;

    return 0;
}

// input
//  Enter haystack: letusad
//  Enter needle: sad

// output
//  Output: 4
