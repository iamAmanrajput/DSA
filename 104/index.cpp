// LC (HARD) - wildcard Matching

#include <string>
using namespace std;

bool isMatchHelper(string &s, int si, string &p, int pi)
{
    // base case
    if (si == s.size() && pi == p.size())
    {
        return true;
    }

    // return true if all * exist in p
    if (si == s.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*')
            {
                return false;
            }
            pi++;
        }
        return true;
    }

    // single char matching
    if (si < s.size() && pi < p.size() && (s[si] == p[pi] || '?' == p[pi]))
    {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }

    if (pi < p.size() && p[pi] == '*')
    {
        // treat * as empty or null
        bool caseA = isMatchHelper(s, si, p, pi + 1);

        // let * consume 1 character
        bool caseB = (si < s.size()) && isMatchHelper(s, si + 1, p, pi);

        return caseA || caseB;
    }

    // char doesn't match
    return false;
}

bool isMatch(string s, string p)
{
    int si = 0; // pointer index of s string
    int pi = 0; // pointer index of p string

    return isMatchHelper(s, si, p, pi);
}
