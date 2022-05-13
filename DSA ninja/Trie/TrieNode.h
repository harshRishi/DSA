class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    // construtor
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) // clear all the garbage address
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// class TrieNode
// {
// private:
//     char data;
//     TrieNode **children;
//     bool isTerminal;

// public:
//     TrieNode(char data);
//     ~TrieNode();
// };

// TrieNode::TrieNode(int data)
// {
//     this->data = data;
//     children = new TrieNode *[26];
//     isTerminal = false;
// }

// TrieNode::~TrieNode()
// {
// }
