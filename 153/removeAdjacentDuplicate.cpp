// Leetcode Problem 1047. Remove All Adjacent Duplicates In String
// # Using Stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string st = ""; // use string as a stack

        for (char c : s)
        {
            if (!st.empty() && st.back() == c)
            {
                st.pop_back(); // duplicate → remove
            }
            else
            {
                st.push_back(c); // no duplicate → add
            }
        }
        return st;
    }
};

int main()
{
    Solution obj;

    string s = "abbaca"; // TEST CASE
    cout << "Input:  " << s << endl;
    cout << "Output: " << obj.removeDuplicates(s) << endl;

    return 0;
}
