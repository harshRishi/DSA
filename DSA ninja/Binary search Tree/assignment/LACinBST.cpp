BinaryTreeNode<int> *LCAHelper(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL || root->data == a || root->data == b)
        return root;

    if (root->data < a && root->data < b) // in Case both values are less than root' data
        return LCAHelper(root->right, a, b);

    else if (root->data > a && root->data > b) // in cas both values are larger than root's data
        return LCAHelper(root->left, a, b);

    // In case one of them is larger than other one is smaller
    BinaryTreeNode<int> *leftAns = LCAHelper(root->left, a, b);
    BinaryTreeNode<int> *rightAns = LCAHelper(root->right, a, b);

    if (leftAns && rightAns) // if both are non nuLL
        return root;

    if (!leftAns && !rightAns) // if both are nuLL
        return NULL;

    else if (leftAns) // one is non nULL [the case where both are NULL than it will return NULL using bAse Case]
        return leftAns;

    return rightAns; //if one is non null
}

int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    BinaryTreeNode<int> *ans = LCAHelper(root, a, b);

    return ans ? ans->data : -1;
}