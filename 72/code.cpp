// Longest Common Prefix

#include <iostream>
#include <vector>
#include <algorithm> // sort function ke liye

using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0]; // Agar sirf ek string hai, wahi prefix hoga

    // Sorting se first aur last string lexicographically sabse alag hongi
    sort(strs.begin(), strs.end());

    string common = ""; // Common prefix store karne ke liye
    int n = strs.size();
    string first = strs[0], last = strs[n - 1]; // Pehli aur aakhri string le rahe hain

    // Dono strings ka common prefix find karna hai
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        { // Jaise hi mismatch mile, break kar do
            return common;
        }
        common += first[i]; // Common character ko add karo
    }

    return common; // Final common prefix return karo
}

int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}

// input
//  Enter number of strings: 3
//  Enter strings:
//  flower
//  flow
//  flight

// output
//  Longest Common Prefix: fl