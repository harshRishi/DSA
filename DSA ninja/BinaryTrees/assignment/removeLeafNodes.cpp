BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL) // Base Case
        return NULL;

    if (root->left == NULL && root->right == NULL) // small Calc
        return NULL;

    BinaryTreeNode<int> *lAns = removeLeafNodes(root->left); // RC on left
    BinaryTreeNode<int> *rAns = removeLeafNodes(root->right); // RC on right
 
    root->left = lAns; // now connect the left subTree root Node with the main root
    root->right = rAns; // now connect the right subTree root Node with the main root
 
    return root;
}