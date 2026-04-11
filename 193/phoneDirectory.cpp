// GFG Problem Phone directory

#include <bits/stdc++.h>
using namespace std;

// Trie Node Definition
class TrieNode
{
public:
    char data;              // character stored at node
    TrieNode *children[26]; // pointers for a-z
    bool isTerminal;        // marks end of a word

    TrieNode(char d)
    {
        data = d;

        // initialize all children as NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

// Function to insert a word into Trie
void insertWord(TrieNode *root, string word)
{

    // base case: word finished
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode *child;

    // if already exists
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // create new node
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursive call for remaining word
    insertWord(child, word.substr(1));
}

class Solution
{

    // DFS traversal to collect all suggestions
    void storeSuggestions(TrieNode *curr, vector<string> &temp, string &prefix)
    {

        // if current node is end of word
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        // traverse all possible children (a-z)
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int index = ch - 'a';
            TrieNode *next = curr->children[index];

            if (next != NULL)
            {
                prefix.push_back(ch);                 // add character
                storeSuggestions(next, temp, prefix); // recursion
                prefix.pop_back();                    // backtrack
            }
        }
    }

    // Function to generate suggestions for each prefix
    vector<vector<string>> getSuggestions(TrieNode *root, string input)
    {

        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < input.size(); i++)
        {

            char lastch = input[i];
            prefix.push_back(lastch); // build prefix

            int index = lastch - 'a';
            TrieNode *curr = prev->children[index];

            // if no matching prefix found
            if (curr == NULL)
            {

                // fill remaining prefixes with "0"
                while (i < input.size())
                {
                    output.push_back({"0"});
                    i++;
                }
                break;
            }
            else
            {
                vector<string> temp;

                // collect suggestions
                storeSuggestions(curr, temp, prefix);

                // if no suggestion found
                if (temp.size() == 0)
                {
                    temp.push_back("0");
                }

                output.push_back(temp);
                prev = curr;
            }
        }
        return output;
    }

public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {

        // sort contacts lexicographically
        sort(contact, contact + n);

        // create root of Trie
        TrieNode *root = new TrieNode('-');

        // insert all contacts into Trie
        for (int i = 0; i < n; i++)
        {
            insertWord(root, contact[i]);
        }

        // return suggestions
        return getSuggestions(root, s);
    }
};

// -------------------- MAIN FUNCTION --------------------
int main()
{

    Solution obj;

    // Test case
    int n = 5;
    string contacts[] = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";

    vector<vector<string>> result = obj.displayContacts(n, contacts, searchWord);

    // Print result
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Prefix " << i + 1 << ": ";
        for (auto word : result[i])
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

// Prefix 1: mobile moneypot monitor mouse mousepad
// Prefix 2: mobile moneypot monitor mouse mousepad
// Prefix 3: mouse mousepad
// Prefix 4: mouse mousepad
// Prefix 5: mouse mousepad