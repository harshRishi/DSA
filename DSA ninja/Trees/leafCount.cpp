int getLeafNodeCount(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    { // edge case
        return 0;
    }
    int totalLeaf = 0;

    if (root->children.size() == 0) // if we found that their is no child of a parent that means it's a leaf so simply return 1;
    {
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        totalLeaf += getLeafNodeCount(root->children[i]);
    }
    return totalLeaf;
}