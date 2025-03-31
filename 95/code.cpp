// last occurance of a character
// #Approach 1 left to right

#include <iostream>
#include <vector>
using namespace std;

void findocc(string &s, int &ans, int i)
{
    if (s[i] == '\0')
    {
        return;
    }

    if (s[i] == 'd')
    {
        ans = i;
    }
    findocc(s, ans, i + 1);
}

int main()
{

    string s = "abcddedg";
    int ans = 0;
    int i = 0;

    findocc(s, ans, i);

    cout << ans;

    return 0;
}

// output
// 6