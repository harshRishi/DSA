#include <iostream>
using namespace std;

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    { // construtor
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() // it will take root info from "this" keyword
    { // distrutor
        delete left;
        delete right;
    }
};