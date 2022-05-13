void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) // Base Case
    {
        return;
    }
    // Write your code here
    cout << root->data << " "; // first print root
    preOrder(root->left); // than left
    preOrder(root->right); // and then rigth
}