void preOrder(TreeNode<int> *root)
{
    // Edge case where some sent root as NULL
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}