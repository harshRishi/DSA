#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// ----------------------------------------method one ------------------------//
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    // Write your code here
    if (root == NULL) // base Case
    {
        return -1;
    }

    if (root->data == a || root->data == b) // in Case root itself is the highest Ancestor
    {
        return root->data;
    }

    int leftAns = getLCA(root->left, a, b);
    int rightAns = getLCA(root->right, a, b);

    if (leftAns == -1 && rightAns == -1) // if both childs are NULL
        return -1;

    else if (leftAns == -1 && rightAns != -1) // if leftCHild is nULL
        return rightAns;

    else if (leftAns != -1 && rightAns == -1) // if Right Child is nULL
        return leftAns;

    else // if both of them are Not NULL, this means if both are comming up with right and left of root than they must share only root as there common Ancestor
        return root->data;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}