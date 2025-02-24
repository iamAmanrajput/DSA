// remove-all-adjacent-duplicates-in-string (LC)

#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    int i = 0;
    while (i < s.length())
    {
        if (i + 1 < s.length() && s[i] == s[i + 1])
        {
            s.erase(i, 2);
            if (i > 0)
                i--;
        }
        else
        {
            i++;
        }
    }
    return s;
}

int main()
{
    // Test Cases
    string str1 = "abbaca"; // Expected Output: "ca"
    string str2 = "azxxzy"; // Expected Output: "ay"
    string str3 = "aabccb"; // Expected Output: ""
    string str4 = "a";      // Expected Output: "a"
    string str5 = "aabbcc"; // Expected Output: ""

    cout << "Input: " << str1 << " -> Output: " << removeDuplicates(str1) << endl;
    cout << "Input: " << str2 << " -> Output: " << removeDuplicates(str2) << endl;
    cout << "Input: " << str3 << " -> Output: " << removeDuplicates(str3) << endl;
    cout << "Input: " << str4 << " -> Output: " << removeDuplicates(str4) << endl;
    cout << "Input: " << str5 << " -> Output: " << removeDuplicates(str5) << endl;

    return 0;
}
