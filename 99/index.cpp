// Remove all Occurance of a SubArray -- Using Recursion

#include <iostream>
#include <string>
using namespace std;

void removeocc(string &s, string &part)
{

    int found = s.find(part);
    if (found != string::npos)
    {
        // string found , remove it
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part + right_part;
        removeocc(s, part);
    }
    else
    {
        // base case -> no substr found;
        return;
    }
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";

    removeocc(s, part);
    return 0;
}
