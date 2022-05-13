#include <limits.h>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    // Write your code here
    // Base Case
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = INT_MAX;  // minimum
        ans.second = INT_MIN; // maximun
        return ans;
    }

    pair<int, int> ans;
    ans.first = root->data; // we consider this root as minimum 
    ans.second = root->data; // we consider this root as max

    pair<int, int> left_ans = getMinAndMax(root->left);   // mini ans max from leftSubTree
    pair<int, int> right_ans = getMinAndMax(root->right); // mini ans max from rightSubTree

    if (left_ans.first < ans.first) // if mini is from the left child
    {
        ans.first = left_ans.first;
    }
    if (left_ans.second > ans.second) // if max is from the left child
    {
        ans.second = left_ans.second;
    }

    if (right_ans.first < ans.first) // if mini is from the right child
    {
        ans.first = right_ans.first;
    }
    if (ans.second < right_ans.second) // if max is from the right child
    {
        ans.second = right_ans.second;
    }
    return ans;
}