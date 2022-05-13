int getLargeNodeCount(TreeNode<int> *root, int x)
{
    // Write your code here
    if (root == NULL) // edge case
    {
        return 0;
    }

    int ans = 0;
    if (root->data > x) // we're doing calc for root and rest will be handled by recursion
    {
        ans++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += getLargeNodeCount(root->children[i], x); // this recursion will bring their ans and will be added in our ans
    }

    return ans;
}