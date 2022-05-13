void printPostOrder(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    { // edge Case
        return;
    }

    for (int i = 0; i < root->children.size(); i++) // first get everything in the stack and then print current root one by one
    {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}