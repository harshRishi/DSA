bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here
    if (root1->data != root2->data || root1->children.size() != root2->children.size()) // here if root data ore not same OR root's child vector size is not same return false
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++) // this is our recursive loop
    {
        return areIdentical(root1->children[i], root2->children[i]);
    }

    return true;
}