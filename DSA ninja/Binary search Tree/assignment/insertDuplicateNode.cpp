void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;

    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);

    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data); // creaeted a new node with root's data
    BinaryTreeNode<int> *temp;                                          // created a temp variable to store root's left

    temp = root->left;
    root->left = newNode;
    newNode->left = temp;
}