TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    TreeNode<int> *max = new TreeNode<int>(root->data);
    
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *childMax = maxDataNode(root->children[i]);
        if ((childMax->data) > (max->data))
        {
            max = childMax;
        }
    }
    return max;
}