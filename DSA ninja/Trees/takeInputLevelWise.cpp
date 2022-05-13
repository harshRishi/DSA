#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData; // here we asked for root data
    cout << "Enter root Data!" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData); // here we've created the root Node

    //make Queue for our TreeNodes so tht we can take level wise input
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root); // here we've pushed our root into queue for futher iterations

    while (!pendingNodes.empty()) // run loop until our queue is empty which will end after our takeInput is finished taking input
    {
        TreeNode<int> *front = pendingNodes.front(); // taking the front treeNode
        pendingNodes.pop();

        cout << "Enter total Number of Child of " << front->data << endl; // asked for totl num of child of the current TreeNode
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th Child of " << front->data << endl;
            cin >> childData;
            // here it is very important to make child treeNode dyamically so that it have the scope out of this for and while Loop
            TreeNode<int> *child = new TreeNode<int>(childData); // here we have created a child TreeNode with childData in it.
            front->children.push_back(child);                    // here we've connected the child with repective parent
            // Now push this child TreeNode in our queue so tht in later level we can ask for there child as well
            pendingNodes.push(child);
        }
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

    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    delete root; // here we're calling the destrutor which will call ~TreeNode()
}