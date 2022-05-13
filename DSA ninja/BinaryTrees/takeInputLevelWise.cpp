#include <iostream>
#include <queue>
#include "BinaryTreeNodeClass.h"
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    if (rootData == -1) // aksing if user wants to make leaf node i.e no more childrens or left rigth
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front(); // taking front element out of the queue
        pendingNodes.pop();                                // deleting front element out of queue

        cout << "Enter Left Child of " << front->data << endl;
        int leftOne;
        cin >> leftOne;
        if (leftOne != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftOne); // creted left Child
            front->left = leftChild;                                           // connected left CHild with respective Parent
            pendingNodes.push(leftChild);                                      // after making it push it in the queue for further data entery
        }

        cout << "Enter Rigth Child of " << front->data << endl;
        int rightOne;
        cin >> rightOne;
        if (rightOne != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightOne); // creted rigth Child
            front->rigth = rightChild;                                           // connected rigth CHild with respective Parent
            pendingNodes.push(rightChild);                                       // after making it push it in the queue for further data entery
        }
    }

    return root;
}

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

/*
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
*/

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

    BinaryTreeNode<int> *root = takeInputLevelWise();

    printTree(root);
    delete root;
}