// Leetcode Problem 71. Simplify Path

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursively build final answer from stack (in correct order)
    void buildAns(stack<string> &st, string &ans)
    {
        if (st.empty())
        {
            return;
        }

        string temp = st.top(); // store top component
        st.pop();               // pop for recursive traversal

        buildAns(st, ans); // process remaining items

        ans += temp; // append component while coming back
    }

    string simplifyPath(string path)
    {
        stack<string> st;
        int i = 0;

        // Parse path string
        while (i < path.size())
        {

            int start = i;
            int end = i + 1;

            // Move end pointer to next '/'
            while (end < path.size() && path[end] != '/')
            {
                end++;
            }

            // Extract substring like "/a", "/..", "/b", etc.
            string minPath = path.substr(start, end - start);

            i = end; // move pointer ahead

            // Ignore "/" and "/." (current directory)
            if (minPath == "/" || minPath == "/.")
            {
                continue;
            }

            // If it's a directory name → push into stack
            if (minPath != "/..")
            {
                st.push(minPath);
            }
            // If ".." → pop the last directory if stack not empty
            else if (!st.empty())
            {
                st.pop();
            }
        }

        // Final ans starts with "/" only if stack is empty
        string ans = st.empty() ? "/" : "";

        // Build final canonical path
        buildAns(st, ans);

        return ans;
    }
};

// -----------------------------------------------------
//                        MAIN + TESTCASE
// -----------------------------------------------------
int main()
{
    Solution sol;

    // Testcase
    string path = "/a/./b/../../c/";

    cout << "Input Path: " << path << endl;
    cout << "Simplified Path: " << sol.simplifyPath(path) << endl;

    return 0;
}

// Input
// /a/./b/../../c/

// Output
// /c
