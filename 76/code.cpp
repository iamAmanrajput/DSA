// group anagram -- (LC)
// # Approach 1 -- using sort

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp; // Map to store sorted string as key and original anagrams as values

        // Creating mapping of sorted string -> list of anagrams
        for (auto str : strs)
        {
            string s = str;
            sort(s.begin(), s.end()); // Sorting the string to get the key
            mp[s].push_back(str);     // Store the original string in map
        }

        vector<vector<string>> ans;

        // Iterating through the map and pushing grouped anagrams into ans
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"}; // Input list of strings

    Solution solution;                                            // Creating object of Solution class
    vector<vector<string>> result = solution.groupAnagrams(strs); // Calling function

    // Printing the grouped anagrams
    cout << "Grouped Anagrams: " << endl;
    for (const auto &group : result)
    {
        cout << "[ ";
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

// output

// [ bat ]
// [ eat tea ate ]
// [ tan nat ]