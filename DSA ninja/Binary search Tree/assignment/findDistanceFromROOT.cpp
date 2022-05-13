int findDistance(Node *root, int x)
{
    // Base case
    if (root == NULL)
        return -1;

    // Initialize distance
    int dist = -1;

    if ((root->data == x) || (dist = findDistance(root->left, x)) >= 0 || (dist = findDistance(root->right, x)) >= 0)
        return dist + 1;

    return dist;
}