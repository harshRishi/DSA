class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
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
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    /*Approch*/
    /*
    - Find the TrieNode where where our patterns end {findwords will do that for us}
    - than from that TrieNode print eveery possible word {allPossibleWords will do that for us}
    -
    */

    TrieNode *findWords(TrieNode *root, string pattern)
    {
        // Base Case
        if (pattern.size() == 0)
            return root;

        int i = pattern[0] - 'a';
        TrieNode *child;
        if (root->children[i] != NULL)
        {
            child = root->children[i];
        }
        else // in Case we didn't found char at 0th index so simply return NULL instead of the TrieNode
        {
            return NULL;
        }
        // recursive Call
        return findWords(child, pattern.substr(1));
    }

    void allPossibleWords(TrieNode *root, string pattern)
    {
        if (root->isTerminal == true) // if root found to be terminal print the word
        {
            cout << pattern << endl;
        }
        for (int i = 0; i < 26; i++) // check all char present in the Trie after pattern
        {

            if (root->children[i] != NULL)
            {
                TrieNode *child = root->children[i];
                // Call Recursion
                allPossibleWords(child, pattern + child->data); // keep adding new char to our pattern so that we can print the words if we finds terminal
            }
        }
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // Write your code here
        for (int i = 0; i < input.size(); i++) // Make A TRie
        {
            insertWord(root, input[i]);
        }

        TrieNode *util = findWords(root, pattern);

        if (util != NULL)
        {
            allPossibleWords(util, pattern);
        }
    }
};