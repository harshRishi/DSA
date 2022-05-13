int getSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    { // Base Case
        return 0;
    }
    return root->data + getSum(root->left) + getSum(root->right); // sum of root + leftSubTree + rightSubtree
}