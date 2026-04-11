// Scratch Implementation of Trie
#include <iostream>
using namespace std;

// Trie Node structure
class TrieNode
{
public:
    char data;              // stores character of the node
    TrieNode *children[26]; // array of pointers for 26 uppercase letters
    bool isTerminal;        // true if node represents end of a valid word

    // Constructor to initialize node
    TrieNode(char d)
    {
        this->data = d;

        // Initialize all children as NULL (no child initially)
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        // Initially node is not terminal
        this->isTerminal = false;
    };
};

// Function to insert a word into Trie
void insertWord(TrieNode *root, string word)
{
    // Base case: if word becomes empty
    // Mark current node as terminal (end of word)
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    // Take first character of word
    char ch = word[0];

    // Calculate index (mapping character to 0-25)
    int index = ch - 'A';

    TrieNode *child;

    // If character already exists in Trie
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // If character not present, create new node
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursive call for remaining substring
    insertWord(child, word.substr(1));
};

// Function to search a word into Trie
bool searchWord(TrieNode *root, string word)
{
    // Base case:
    // If word becomes empty, check if current node marks end of a valid word
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    // Take first character of the word
    char ch = word[0];

    // Convert character into index (0–25)
    int index = ch - 'A';

    TrieNode *child;

    // Check if current character exists in Trie
    if (root->children[index] != NULL)
    {
        // If present, move to that child node
        child = root->children[index];
    }
    else
    {
        // If character not found, word does not exist in Trie
        return false;
    }

    // Recursive call for remaining substring of the word
    return searchWord(child, word.substr(1));
}

// Function to delete a word into Trie
void deleteWord(TrieNode *root, string word)
{
    // Base case:
    // If the word becomes empty, we have reached the end of the word
    if (word.length() == 0)
    {
        // Only unmark if this node was marking the end of a valid word
        if (root->isTerminal)
        {
            root->isTerminal = false;
        }
        return;
    }

    // Take the first character of the word
    char ch = word[0];

    // Convert character to index (0–25 for uppercase letters)
    int index = ch - 'A';

    TrieNode *child;

    // If the character path does not exist in Trie,
    // it means the word does not exist → do nothing
    if (root->children[index] == NULL)
    {
        return;
    }
    else
    {
        // Move to the corresponding child node
        child = root->children[index];
    }

    // Recursive call for the remaining substring
    deleteWord(child, word.substr(1));
}

int main()
{
    // Create root node (dummy character)
    TrieNode *root = new TrieNode('-');

    // Insert word into Trie
    insertWord(root, "coding");
    insertWord(root, "CODING");
    insertWord(root, "CODE");
    insertWord(root, "CODER");
    insertWord(root, "COOL");
    insertWord(root, "CAT");

    // Test search
    cout << searchWord(root, "CODING") << endl; // 1 (true)
    cout << searchWord(root, "CODE") << endl;   // 1 (true)
    cout << searchWord(root, "CO") << endl;     // 0 (false, prefix hai but word nahi)
    cout << searchWord(root, "CAT") << endl;    // 1 (true)
    cout << searchWord(root, "DOG") << endl;    // 0 (false)

    // delete
    deleteWord(root, "CODE");

    cout << searchWord(root, "CODE") << endl;   // 0 (false)
    cout << searchWord(root, "CODING") << endl; // 1 (true)

    return 0;
}