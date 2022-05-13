void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    { // base Case
        return;
    }

    if ((root->left && !root->right) || (root->right && !root->left)) // enter if there if only left or only right of the current root
    {
        if (root->left)
        {
            cout << root->left->data << " "; // print data of the left of the current root else do following
        }
        else
        {
            cout << root->right->data << " ";
        }
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}