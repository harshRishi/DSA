#include <iostream>
#include "BinaryTreeNodeClass.h"
// we'll going to use max and pair class which are inbuilt
#include <queue>
using namespace std;

/*
class Pair
{
public:
    int height;
    int diameter;

    Pair(int height, int diameter) // parameterized constructor
    {
        this->diameter = diameter;
        this->heigth = height;
    }
};
*/

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }

    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

// ********************************  Diameter of Binary Tree *************************??
// here we'll calc heigth of the tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base Case
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right)); // here max will be screened out and one will be added to it as heigth of root will be 1
}

/*
    int diameter(BinaryTreeNode<int> * root) // Time Complexcity is O(n^2); Very Bad
    {
        // Base Case
        if (root == NULL)
            return 0;

        int option1 = heigth(root->left) + heigth(root->rigth); // if there is any rigth or left of the current root
        int option2 = diameter(root->left);
        int option3 = diameter(root->right);

        return max(option1, max(option2, option3));
    }
    */

/*
 Idea behind is we have three ways to find diaemter of the tree
 Case 1: find height of left and right subtree and them
 Case 2: find diameter of leftTree
 case3: find diameter of rightSub tree
 now this diamter calculation will call height again so we used pair class object where we receive height and diamter of the subtressss
*/

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    // this is our Base Case
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 0;  //  First is height
        ans.second = 0; // second is diameter
        return ans;
    }

    pair<int, int> leftAns = heightDiameter(root->left);   // this will bring us the height and diameter of the left subtree
    pair<int, int> rightAns = heightDiameter(root->right); // this will bring us the height and diameter of the right subtree

    int left_height = leftAns.first;
    int left_diameter = leftAns.second;
    int right_height = rightAns.first;
    int right_diameter = rightAns.second;

    pair<int, int> ans;
    ans.first = 1 + max(left_height, right_height); // tis will calc the child Height
    ans.second = max((left_height + right_height), max(left_diameter, right_diameter)); // this will calc all there possible options out which we have discussed
    // and out of all three we find max and returned it

    return ans;
}

// TIME COMPLEXCITY IS -- O(n); Very Good  //  try Input 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1 ?? ans - height 5, diameter 6;
int diameter(BinaryTreeNode<int> *root) // Time Complexcity is O(n^2); Very Bad
{
    return heightDiameter(root).second; // we want diameter of the pair ans so we know inbuilt pair have first and second as it's pair we have considered first as hieght and second as diameter.
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;
    delete root;
}