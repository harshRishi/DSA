#include <iostream>
#include "BinaryTreeNodeClass.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL) // Base Case
    {
        return;
    }

    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->rigth)
    {
        cout << "R" << root->rigth->data;
    }
    cout << endl;

    printTree(root->left);
    printTree(root->rigth);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;

    if (rootData == -1) // if user entered -1 we'll simply return
    {
        return NULL;
    }
    // getting to this point means user want to enter something into tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    // below we're making and connecting left and right of the parent BtNode
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rigthChild = takeInput();
    root->left = leftChild;
    root->rigth = rigthChild;

    return root;
}

int main()
{
    /*
    // here we're making seperated BinaryTreeNode
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1; // here we've made the connections inside of Bt.
    root->rigth = node2;
    */

    BinaryTreeNode<int> *root = takeInput();

    printTree(root);
    delete root;
}