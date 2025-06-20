// Valid Parenthesis -- (LC)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursive function to generate valid parentheses
void solve(vector<string> &ans, int open, int close, string &output)
{
    // Base Case: If no more brackets can be added
    if (open == 0 && close == 0)
    {
        ans.push_back(output); // Add valid combination
        return;
    }

    // If we still have opening brackets left
    if (open > 0)
    {
        output.push_back('(');               // Add opening bracket
        solve(ans, open - 1, close, output); // Recursive call
        output.pop_back();                   // Backtrack: remove last character
    }

    // We can add closing bracket only if more closing brackets are left
    // than opening ones to ensure valid expression
    if (close > open)
    {
        output.push_back(')');               // Add closing bracket
        solve(ans, open, close - 1, output); // Recursive call
        output.pop_back();                   // Backtrack
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string output = "";
    solve(ans, n, n, output);
    return ans;
}

// Main function to test the logic
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> result = generateParenthesis(n);

    cout << "Valid parentheses combinations for n = " << n << ":\n";
    for (const string &s : result)
    {
        cout << s << endl;
    }

    return 0;
}

// Input:
// Enter the value of n: 3

// Output:
// Valid parentheses combinations for n = 3:
// ((()))
// (()())
// (())()
// ()(())
// ()()()
