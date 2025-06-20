// 17. Letter Combinations of a Phone Number --(LC)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursive function to generate all letter combinations
void solve(vector<string> &ans, int index, string &output, const string &digits, const vector<string> &mapping)
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int digit = digits[index] - '0';
    string value = mapping[digit];

    for (int i = 0; i < value.size(); i++)
    {
        output.push_back(value[i]);
        solve(ans, index + 1, output, digits, mapping);
        output.pop_back(); // backtrack
    }
}

// Wrapper function to prepare data and start recursion
vector<string> letterCombinations(const string &digits)
{
    vector<string> ans;
    if (digits.empty())
        return ans;

    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    string output = "";
    solve(ans, 0, output, digits, mapping);

    return ans;
}

int main()
{
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = letterCombinations(digits);

    cout << "\nLetter combinations:\n";
    for (const string &combination : result)
    {
        cout << combination << endl;
    }

    return 0;
}

// Input:
// Enter digits (2-9): 23

// Output:
// Letter combinations:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf