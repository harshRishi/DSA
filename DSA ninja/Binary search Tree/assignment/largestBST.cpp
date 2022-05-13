// ====================== code BY me More efficient with time Complexcity O(n)
#include <climits>
class quad
{
public:
    int min, max, height;
    bool isBST;
};

quad largestBST(BinaryTreeNode<int> *root)
{
    if (root == NULL) // Base Case {no root means zero height}
    {
        quad ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        ans.height = 0;
        return ans;
    }

    quad lAns = largestBST(root->left);
    quad rAns = largestBST(root->right);

    int finalMin = min(root->data, min(lAns.min, rAns.min));
    int finalMax = max(root->data, max(lAns.max, rAns.max));
    bool finalCheck = (root->data > lAns.max && root->data <= rAns.min && lAns.isBST && rAns.isBST);
    // calc for height
    int finalHeight;
    if (finalCheck)
    {
        finalHeight = 1 + max(lAns.height, rAns.height); // if our lTree is a BST including the root than that means we need to return ans + 1 to include the root
    }
    else // if our root isn't a bst than we should return only the max of ans comming from the subTrees without add up one to itssss 
    {
        finalHeight = max(lAns.height, rAns.height);
    }

    quad finalAns;
    finalAns.min = finalMin;
    finalAns.max = finalMax;
    finalAns.isBST = finalCheck;
    finalAns.height = finalHeight;
    return finalAns;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return NULL;

    return largestBST(root).height;
}

// ====================== Method 2  less efficient by TA with time complexcity O(n*h)
// int ans(0),ans1(0),m(0),n(0);
// #include <bits/stdc++.h>
// int height(BinaryTreeNode<int>*root)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }

//     return max(height(root->left),height(root->right))+1;
// }
// int minimum(BinaryTreeNode<int>* root){
//     if(root==NULL)
//         return INT_MAX;
//     return min(root->data,min(minimum(root->left),minimum(root->right)));
// }

// int maximum(BinaryTreeNode<int>* root){
//     if(root==NULL)
//         return INT_MIN;
//     return max(root->data,max(maximum(root->left),maximum(root->right)));
// }
// bool isBST(BinaryTreeNode<int> *root){

//  if(root==NULL)
//         return true;
//     int min = minimum(root->right);
//     int max = maximum(root->left);

//     bool output = (root->data>max && root->data<min && isBST(root->left) && isBST(root->right));
//     return output;
// }

// int largestBSTSubtree(BinaryTreeNode<int> *root) {
//     if(isBST(root))
//     {
//         return height(root);
//     }
//     else
//     {
//       return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));
//     }
// }