// Leetcode Problem 14. Longest Common Prefix

#include <iostream>
#include <vector>
using namespace std;

// Trie Node Definition
class TrieNode
{
public:
    char data;              // stores character
    TrieNode *children[26]; // pointers for a-z
    bool isTerminal;        // marks end of a word
    int childCount;         // number of children

    TrieNode(char d)
    {
        data = d;

        // initialize all children as NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
    }
};

class Solution
{
public:
    // Function to insert a word into Trie
    void insertWord(TrieNode *root, string word)
    {
        // Base case: if word is empty → mark terminal
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'a'; // map 'a'-'z' → 0-25

        TrieNode *child;

        // If character already exists → move to that node
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // If not exists → create new node
            child = new TrieNode(ch);

            root->childCount++;            // increase child count
            root->children[index] = child; // link new node
        }

        // Recursive call for remaining string
        insertWord(child, word.substr(1));
    }

    // Function to find Longest Common Prefix
    void findLcp(string first, string &ans, TrieNode *root)
    {
        // Traverse characters of first string
        for (int i = 0; i < first.size(); i++)
        {
            char ch = first[i];

            // Condition 1: Only one child → continue LCP
            if (root->childCount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                // More than one child → branching → stop
                break;
            }

            // Condition 2: If any word ends → stop
            if (root->isTerminal)
            {
                break;
            }
        }
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        // Edge case
        if (strs.size() == 0)
            return "";

        // Create root node
        TrieNode *root = new TrieNode('-');

        // Insert all strings into Trie
        for (int i = 0; i < strs.size(); i++)
        {
            insertWord(root, strs[i]);
        }

        string ans = "";
        string first = strs[0];

        // Find LCP using first string
        findLcp(first, ans, root);

        return ans;
    }
};

// ----------- MAIN FUNCTION (TEST CASE) -----------
int main()
{
    Solution obj;

    // Test case 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "LCP: " << obj.longestCommonPrefix(strs1) << endl;
    // Expected: "fl"

    // Test case 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "LCP: " << obj.longestCommonPrefix(strs2) << endl;
    // Expected: ""

    // Test case 3
    vector<string> strs3 = {"coding", "code", "coder"};
    cout << "LCP: " << obj.longestCommonPrefix(strs3) << endl;
    // Expected: "cod"

    return 0;
}