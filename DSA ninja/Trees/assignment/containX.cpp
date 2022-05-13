bool isPresent(TreeNode<int> *root, int x)
{
    // Write your code here
    if (root->data == x) // if current root have x return true
    {
        return true;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        // if we find any child where we found x this roq will return true
        bool childAns = isPresent(root->children[i], x); // Recursive call
        if (childAns)
        {
            return true;
        }
    }
    return false; // this means every childAns is false so return false.
}