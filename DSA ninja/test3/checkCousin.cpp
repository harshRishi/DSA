int depth(BinaryTreeNode<int> *root, int node)
{
    if (root == NULL)
        return -1;
    if (node == root->data)
        return 0;
    int left = depth(root->left, node);
    if (left != -1)
        return 1 + left;
    else
    {
        int right = depth(root->right, node);
        if (right != -1)
            return 1 + right;
        else
            return -1;
    }
}
bool isSibling(BinaryTreeNode<int> *root, int p, int q)
{
    // Write your code here
    if (root == NULL)
        return false;
    if (root->left != NULL && root->right != NULL)
    {
        if (root->left->data == p && root->right->data == q)
            return true;
        else if (root->left->data == q && root->right->data == p)
            return true;
        else
            return isSibling(root->left, p, q) || isSibling(root->right, p, q);
    }
    if (root->right != NULL)
    {
        return isSibling(root->right, p, q);
    }
    else
        return isSibling(root->left, p, q);
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == NULL)
        return false;
    return ((depth(root, p) == depth(root, q)) && (!isSibling(root, p, q)));
}