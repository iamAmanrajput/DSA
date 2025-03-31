#include <iostream>
using namespace std;

void reversestr(string &s, int i, string &ans)
{
    if (i < 0)
    {
        return;
    }
    ans.push_back(s[i]);
    reversestr(s, i - 1, ans);
}

int main()
{

    string s = "amansingh";
    string ans = "";
    int i = s.size() - 1;
    reversestr(s, i, ans);
    cout << "Reverse string is : " << ans;

    return 0;
}

// output
// Reverse string is : hgnisnama