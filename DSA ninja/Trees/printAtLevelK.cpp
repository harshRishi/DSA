#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

// print at level k from the Root pf the tree
void printAtLevelK(TreeNode<int> *root, int k) // where k is the level we want to print
{
    // edge case
    if (root == NULL) // this is not a base case.
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl; // here the root will be the children after indentation and as every indentation k is also decreased by 1
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int numNodes(TreeNode<int> *root) // function to count total number of TreeNodes
{
    int ans = 1; // this is the ans for root TreeNode

    for (int i = 0; i < root->children.size(); i++) // travelling over the vector children
    {
        ans += numNodes(root->children[i]); // here every TreeNode will bring 1 after recursion and it will be added to the previous ans at the end of the stack call we will end up with total Count
    }
    return ans;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    /*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout << "num: " << numNodes(root) << endl;
    cout << "Level 2:" << endl;
    printAtLevelK(root, 2);
    // TODO delete the tree
    delete root; // here we're calling the destrutor which will call ~TreeNode()
}