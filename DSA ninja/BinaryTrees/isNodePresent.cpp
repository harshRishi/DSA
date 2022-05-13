/* Approch:-
- first if root == NULL (i.e if tree is over) than return false, as this clearify that x is not [present]
- if root isn't nULL than check root's data and compare it with x, return true if matched
- now return true only whole Left or Right SUBTREE comes to be TRUE  
*/

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    // Write your code here

    // Base Case
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x) // if current root have x return true
    {
        return true;
    }

    bool left = isNodePresent(root->left, x);
    if (left) // if left child return true than return true as we have founf x there.
        return true;

    /* node is not found in left,
    so recur on right subtree */
    bool rigth = isNodePresent(root->right, x);
    if (rigth)
        return true;
}