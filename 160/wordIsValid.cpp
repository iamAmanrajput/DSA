// Leetcode Problem 1003. Check If Word Is Valid After Substitutions
// Recursive Approach

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // Base case:
        // Agar string empty ho gayi, matlab saare "abc" remove ho chuke hain
        if (s.size() == 0)
        {
            return true;
        }

        string word = "abc";

        // "abc" ka starting index dhundho
        int pos = s.find(word);

        // Agar "abc" mil gaya
        if (pos != string::npos)
        {
            // "abc" ko string se remove karo
            s.erase(pos, word.length());

            // Remaining string ke liye recursively check karo
            return isValid(s);
        }
        else
        {
            // Agar kahin bhi "abc" nahi mila
            // aur string empty bhi nahi hai
            // to string invalid hai
            return false;
        }
    }
};

int main()
{
    Solution sol;

    // Test cases
    string s1 = "aabcbc"; // valid → "" ban sakti hai
    string s2 = "abcabc"; // valid
    string s3 = "abccba"; // invalid
    string s4 = "";       // valid (already empty)

    cout << "Test 1: " << sol.isValid(s1) << endl; // 1 (true)
    cout << "Test 2: " << sol.isValid(s2) << endl; // 1 (true)
    cout << "Test 3: " << sol.isValid(s3) << endl; // 0 (false)
    cout << "Test 4: " << sol.isValid(s4) << endl; // 1 (true)

    return 0;
}
