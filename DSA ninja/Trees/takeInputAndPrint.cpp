#include <iostream>
#include "TreeNodeClass.h"
using namespace std;

TreeNode<int> *takeInput()
{
    // here we just took the input from the user
    int rootData;
    cout << "Enter the root Data!" << endl;
    cin >> rootData;
    // now copy this rootData to the data of the Root Node
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter Number of Childrens" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) // this loop will enter the total number of children
    {
        TreeNode<int> *child = takeInput(); // this is our recusive call to make a new TreeNode and this will going to return child's ka root Node.
        // now after creating the child TreeNode we need to connect it to the parent children's vector array
        root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL) // remember this isn't a Base Case it's an edge Case where Tree which we get here is empty otherwise we'll get segmentation fault as we our trying to access NULL->data on line number 11
    {
        return;
    }
    cout << root->data << ": "; // here we've printed the data of the root
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++) // this For Loop will work as a Base Case for Our Recursion
    {
        printTree(root->children[i]); // children vecter (dynamic array) ka ith element(which is also a TreeNode) ko recursion mein dal do. so that than that child we be treated as a root and their data will also be printed
    }
}

int main()
{
    /*
    TreeNode<int> *root = new TreeNode<int>(1); // here we have filled the data at the time of creation
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    root->children.push_back(node1); // here we've stored node1 TreeNode in root's children's vector
    root->children.push_back(node2);
    */

    TreeNode<int> *root = takeInput();
    printTree(root);
    delete root; // here we're calling the destrutor which will call ~TreeNode()
}