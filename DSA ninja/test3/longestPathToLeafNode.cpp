vector<int> *longestPath(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    if (!root->left && !root->right)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftans = longestPath(root->left);
    vector<int> *rightans = longestPath(root->right);
    if (!leftans)
    {
        rightans->push_back(root->data);
        return rightans;
    }
    else if (!rightans)
    {
        leftans->push_back(root->data);
        return leftans;
    }
    else
    {
        if (leftans->size() < rightans->size())
        {
            rightans->push_back(root->data);
            delete leftans;
            return rightans;
        }
        else
        {
            leftans->push_back(root->data);
            delete rightans;
            return leftans;
        }
    }
}