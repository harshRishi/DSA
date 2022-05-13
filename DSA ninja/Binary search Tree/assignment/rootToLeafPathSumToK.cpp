/*Approch*/
 /*
 - we'll use a helper function with a empty string s
 - we keep's on adding root->data string to our empty string until we reach the leaf node
 - and in recurion we are passing k value decreased by root's data
 - so after reaching the leaf our string is ready for a print except the leaf it self so to do so we'll explicitly printed the leaf Node
 */

#include <string>
void helper(BinaryTreeNode<int> *root, int k, string s)
{
    // base Case
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL && root->data == k) // if we get to the leaf node and our leftOver k is equal to the leaf node's data than cout str and leafNode data
    {
        cout << s << root->data;
        cout << endl;
        return;
    }

    s = s + to_string(root->data) + " "; // converted root's data into a string and added to our string with space

    helper(root->left, k - root->data, s);
    helper(root->right, k - root->data, s);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    helper(root, k, "");
}