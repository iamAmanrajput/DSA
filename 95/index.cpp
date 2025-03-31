#include <iostream>
#include <vector>
using namespace std;

void findocc(string &s, int &ans, int i)
{
    if (i < 0)
    {
        return;
    }

    if (s[i] == 'd')
    {
        ans = i;
        return;
    }
    findocc(s, ans, i - 1);
}

int main()
{

    string s = "abcddedg";
    int ans = 0;
    int i = s.size() - 1;

    findocc(s, ans, i);

    cout << ans;

    return 0;
}

// output
// 6