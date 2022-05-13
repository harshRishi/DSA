BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{
    // Write your code here
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength - 1]);

    if (postLength == 1)
        return root;

    if (postLength == 0)
        return NULL;

    int i = 0;
    while (inorder[i] != root->data) // this will stop when i will reach root in inorder Traversal
    {
        i++;
    }

    int left_size = i;                   // this is left size which is passeed in the recursive call
    int right_size = inLength - (i + 1); // i.e root plus one.

    BinaryTreeNode<int> *leftSubtree = buildTree(postorder, left_size, inorder, left_size); // travel only left of the post and inorder so giving length according while skipping the root
    BinaryTreeNode<int> *rightSubtree = buildTree(postorder + left_size, right_size, inorder + 1 + left_size, right_size); // travel only rigth of the post and inorder so giving length according while skipping the root

    root->left = leftSubtree; // connect it with the root
    root->right = rightSubtree;
}    