#include "TrieNode.h"
#include <string>

class Trie
{
private:
    TrieNode *root;

public:
    // construtor
    Trie()
    {
        root = new TrieNode('\0'); // here we've created a TrieNode with data NULL and isTerminal false with NULL 26 length array
    }

private:
    void insertWord(TrieNode *root, string word) // insert helper function
    {
        /* Base Case
        - when string size is zero our root is pointing to word's end so make it isTerminal true
        */
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calc
        int i = word[0] - 'a';         // get the index where 0th element is present
        TrieNode *child;               // this node is made so that we can pass it to recursion
        if (root->children[i] != NULL) // we found what were looking for
        {
            child = root->children[i]; // we'll pass this in recursion as a root
        }
        else // In Case we didn't found what we were looking for
        {
            // make a new trieNode with 0th char and attach it with it's parent i.e root->children[i];
            child = new TrieNode(word[0]);
            root->children[i] = child;
        }

        // recusive Call
        insertWord(child, word.substr(1)); // child as new Root and String from 1 to end as 0th is already been included in the word
    }

    bool search(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0) // if we found it's terminal is false that means altho we found endChar but as it is not terminal therefore it is not a word and we should return false
            return root->isTerminal;

        // small Calc
        int i = word[0] - 'a';
        if (root->children[i] != NULL) // don't forget to return
            return search(root->children[i], word.substr(1));
        else
            return false;
    }

    void removeWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminal = false; // this will mark terminal as false and thus now that word is not part of the trie
        }

        // small Calc
        int i = word[0] - 'a';
        TrieNode *child;
        if (root->children[i] != NULL)
        {
            child = root->children[i]; // save the address for recusion
        }
        else
        { // word not found that start with word[0];
            return;
        }
        // if we entered this line than it means our child pointer have the location of word[0] char in root
        // Recusive CAll
        removeWord(child, word.substr(1));

        // by this line we actually have removeWord the word but hasn't delete if it is leafNode i.e usless
        /*delete node which doean't have isTerminal false && have No Children*/
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++) // check if there is any children of child
            {
                if (child->children[i] != NULL) // if we found any child of child at any index than simply return as it is not a useless node
                {
                    return;
                }
            }
            // Coming to this line means we have search every child's chilrens loaction and we didn't find any
            delete child;
            root->children[i] = NULL;
        }
    }

public:
    void insertWord(string word)
    {
        insertWord(this->root, word); // Call helper function
    }

    bool search(string word)
    {
        // Write your code here
        return search(this->root, word);
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};