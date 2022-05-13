#include <vector>
TreeNode<int> *removeLeafNodes(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL || root->numChildren() == 0)
        return NULL;
    vector<int> indexes;
    for (int i = 0; i < root->numChildren(); i++)
    {
        TreeNode<int> *child = root->getChild(i);
        if (child->numChildren() == 0)
            indexes.push_back(i);
    }
    for (int i = indexes.size() - 1; i >= 0; i--)
    {
        int j = indexes[i];
        root->removeChild(j);
    }
    for (int i = 0; i < root->numChildren(); i++)
    {
        TreeNode<int> *child = removeLeafNodes(root->getChild(i));
        if (child == NULL)
            root->removeChild(i);
    }
    return root;
}