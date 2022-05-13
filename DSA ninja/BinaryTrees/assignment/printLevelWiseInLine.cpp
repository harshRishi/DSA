void printLevelWise(BinaryTreeNode<int> *root)
{
    // Write your code here
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL) // enter and insert NULL
        {
            if (pendingNodes.empty()) // this means are Binarytree is over
                break;

            cout << endl;
            pendingNodes.push(NULL);
            continue;
        }

        cout << front->data << " ";
        if (front->left)
        {
            pendingNodes.push(front->left);
        }
        if (front->right)
        {
            pendingNodes.push(front->right);
        }
    }
}