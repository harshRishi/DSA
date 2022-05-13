/*
int height(BinaryTreeNode<int> *root)
{
    // Write our code here
    // Base Case
    if (root == NULL)
    {
        return 0;
    }
    int maxheigth = 0;

    int lHeigth = height(root->left);
    if (maxheigth < lHeigth)
        maxheigth = lHeigth;

    int rHeigth = height(root->right);
    if (maxheigth < rHeigth)
        maxheigth = rHeigth;

    return maxheigth + 1; // we added 1 coz we have to calc root node Also in maxhieght
}
*/

// OR ??

int height(BinaryTreeNode<int> *root)
{
    // Write our code here
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    int lHeigth = height(root->left);
    int rHeigth = height(root->right);

    if (lHeigth > rHeigth)
        return lHeigth + 1; // we added 1 coz we have to calc root node Also in maxhieght
    else
        return rHeigth + 1; // we added 1 coz we have to calc root node Also in maxhieght
}