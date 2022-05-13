void print(BinaryTreeNode<int> *node, int k)
{
    // Base CAse
    if (node == NULL || k < 0)
        return;

    if (k == 0) // reached the k distance from the target node
    {
        cout << node->data << endl;
        return;
    }

    print(node->left, k - 1); // as we go below in the Tree we need to decrease the k value so tht we can measure on wht level we current are;
    print(node->right, k - 1);
}

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int helper(BinaryTreeNode<int> *root, int target, int k)
{
    // base case
    if (root == NULL) // If tree is empty, return -1
        return -1;

    if (root->data == target) // root itself is taget BinaryNode
    {
        // to print all nodes at distance k in subtree rooted with
        // target or root
        print(root, k);
        return 0;
    }

    // if root is not the target we should ask leftChild to get us the distance of target from leftChild so that later we can add 1 to the distance bw leftChild and target
    // If root is at distance k from target, print root
    // Note that leftDistance is Distance of root's left child from target
    int leftDistance = helper(root->left, target, k);

    // if this leftDistance return -1 thn that means target node isn't in thhe leftsubTree
    if (leftDistance != -1)
    {
        // if root itseft is k distance from the taget than print it
        // so to get to the root we need to add 1 to it as leftDistance is from the root's leftchild node
        if (leftDistance + 1 == k)
            cout << root->data << endl;

        // Else go to right subtree and print all k-dl-2 distant nodes
        // Note that the right child is 2 edges away from left child
        else
            print(root->right, k - leftDistance - 2); // -2 coz' 1 for left'child to root and other for root to rightChild

        // Add 1 to the distance and return value for parent calls
        return 1 + leftDistance;
    }

    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int rightDistance = helper(root->right, target, k);
    if (rightDistance != -1)
    {
        if (rightDistance + 1 == k)
            cout << root->data << endl;

        else
            print(root->left, k - rightDistance - 2);

        return 1 + rightDistance;
    }

    // If target was neither present in left nor in right subtree
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    // Write your code here
    int faltu = helper(root, node, k);
}