
/*Approch*/
/*
- here we will going to traver the whole BST  RIGHT ROOT LEFT
- as we know that right is always be greater than left and the root
- now after getting to the right most element we need to sum up the data of root with current sum value
- Now replace the root->data with with calculated sum
- now call recursion on the left subTree
*/

void replace(BinaryTreeNode<int> *root, int *sum)
{
    if (root == NULL) // base Case
        return;

    replace(root->right, sum); // it will going to stop at the right most Node which is max also

    *sum = *sum + root->data;
    root->data = *sum;

    replace(root->left, sum);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    int sum = 0;
    replace(root, &sum);
}