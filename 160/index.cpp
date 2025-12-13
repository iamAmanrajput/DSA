// Leetcode Problem 1003. Check If Word Is Valid After Substitutions
// Stack Approach
// Tc 0(n)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // Agar string 'a' se start hi nahi ho rahi
        // to valid ban hi nahi sakti
        if (s[0] != 'a')
        {
            return false;
        }

        stack<char> st;

        // String ke har character par iterate karo
        for (char ch : s)
        {

            // Case 1: agar 'a' aaya → stack me push
            if (ch == 'a')
            {
                st.push(ch);
            }

            // Case 2: agar 'b' aaya
            else if (ch == 'b')
            {
                // 'b' tabhi valid hai jab stack ka top 'a' ho
                if (!st.empty() && st.top() == 'a')
                {
                    st.push(ch);
                }
                else
                {
                    return false;
                }
            }

            // Case 3: agar 'c' aaya
            else
            {
                // 'c' ke liye pehle 'b' hona chahiye
                if (!st.empty() && st.top() == 'b')
                {
                    st.pop(); // 'b' remove

                    // 'b' ke neeche 'a' hona chahiye
                    if (!st.empty() && st.top() == 'a')
                    {
                        st.pop(); // 'a' remove
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        // Agar saare 'abc' pairs properly remove ho gaye
        // to stack empty hogi → valid
        return st.empty();
    }
};

int main()
{
    Solution sol;

    // Test cases
    string s1 = "aabcbc"; // valid
    string s2 = "abcabc"; // valid
    string s3 = "abccba"; // invalid
    string s4 = "abc";    // valid
    string s5 = "cababc"; // invalid

    cout << "Test 1: " << sol.isValid(s1) << endl; // 1
    cout << "Test 2: " << sol.isValid(s2) << endl; // 1
    cout << "Test 3: " << sol.isValid(s3) << endl; // 0
    cout << "Test 4: " << sol.isValid(s4) << endl; // 1
    cout << "Test 5: " << sol.isValid(s5) << endl; // 0

    return 0;
}
