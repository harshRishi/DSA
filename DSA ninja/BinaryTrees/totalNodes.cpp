int numNodes(BinaryTreeNode<int> *root) // count total number of BtNodes in the Binary Tree
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    return 1 + numNodes(root->right) + numNodes(root->left); // here one is count of root node and than for rest we call recursion on left as well as on rigth
}