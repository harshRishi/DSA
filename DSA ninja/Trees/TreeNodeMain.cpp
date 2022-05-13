#include <iostream>
#include "TreeNodeClass.h"
using namespace std;

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1); // here we have filled the data at the time of creation
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    root->children.push_back(node1); // here we've stored node1 TreeNode in root's children's vector
    root->children.push_back(node2);
}