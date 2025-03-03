// group anagram -- (LC)
// # Approach 2 -- without sort

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Creating hash for a string
    std::array<int, 256> hash(string s)
    {
        std::array<int, 256> hash = {0}; // Initialize hash array with 0

        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++; // Count occurrences of each character
        }
        return hash;
    }

    // Function to group anagrams
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<std::array<int, 256>, vector<string>> mp; // Map to store hash -> list of anagrams

        // Creating mapping of hash -> list of anagrams
        for (auto str : strs)
        {
            mp[hash(str)].push_back(str);
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

// [ tan nat ]
// [ eat tea ate ]
// [ bat ]