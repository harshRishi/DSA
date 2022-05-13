#include <string>
#include <vector>

// my Soultion using recursion while TA gave me iterative solution

class TrieNode
{
public:
    char data;
    TrieNode **children;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
            return false;

        // Recursive call
        return search(child, word.substr(1));
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word)
    {
        // Base Case
        if (word.size() == 0)
            return;

        insertWord(root, word); // small Calc

        /// recursive Call
        insertWord(word.substr(1));
    }

    // make Trie Function
    bool patternMatching(vector<string> vect, string pattern)
    {
        // Write your code here
        Trie ans;
        for (int i = 0; i < vect.size(); i++) // making our trie with vector
        {
            insertWord(vect[i]);
        }
        return search(pattern);
    }
};
