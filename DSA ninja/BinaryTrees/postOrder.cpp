void postOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;

    // here we need to print the child first so instead of stack we used recursion

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}