// find the index of first occurance (LC)
// # using find method

#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
    int ans = haystack.find(needle);
    return (ans == string::npos) ? -1 : ans;
}

int main()
{
    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    int result = strStr(haystack, needle);
    cout << "Output: " << result << endl;

    return 0;
}

// input
//  Enter haystack: letusad
//  Enter needle: sad

// output
//  Output: 4