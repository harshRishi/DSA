BinaryTreeNode<int>* buildTree(int *preOrder, int preLength, int *inOrder, int inLength) {

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preOrder[0]);

    if(preLength == 1)     // base case when only root is present and no left or right node
        return root;
    if(preLength == 0)    //if one of both right or left is present check for 2, 1 2, 1 2;;;dry run it
        return NULL;

    int i = 0;

    while(inOrder[i] != preOrder[0]){ // find index of root in inOrder traversal
        i++;
    }
    //at ith pos we get root so, left size is i not i+1
    int left_size = i;
    int right_size = inLength - (i+1);

    BinaryTreeNode<int> *leftSubtree = buildTree(preOrder + 1, left_size, inOrder, left_size);
    BinaryTreeNode<int> *rightSubtree = buildTree(preOrder + 1 + left_size, right_size, inOrder + 1 
                                                  + left_size, right_size);

    root -> left = leftSubtree;
    root-> right = rightSubtree; 

    return root;
}