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
 // =========================================
BinaryTreeNode<int> *helper(int *input, int si, int ei)
{
    // Base Case
    if (si > ei)
        return NULL;

    int mid = (ei + si) / 2;                                         // mid point of the array calc
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]); // here we made are root which will going to have data of the middle element of the sorted array
    /*
    BinaryTreeNode<int> *leftSubTree = helper(input, si, mid - 1);  // here we have changed the end index, as array is sorted that means element on the left side of the middle index will be smaller and can be used to make leftSubTREE of the BinarySreachTree
    BinaryTreeNode<int> *rightSubTree = helper(input, mid + 1, ei); // here we've changed the start index, as array is sorted that means element in the right side of the middle index will going to be larger and can be used to make rightSubTree of the BST

    // Below we've connect the root to it's right and left subTrees
    root->left = leftSubTree;
    root->right = rightSubTree;
*/
    // we can Also do this way
    // Below we've connect the root to it's right and left subTrees
    root->left = helper(input, si, mid - 1);  // here we have changed the end index, as array is sorted that means element on the left side of the middle index will be smaller and can be used to make leftSubTREE of the BinarySreachTree
    root->right = helper(input, mid + 1, ei); // here we've changed the start index, as array is sorted that means element in the right side of the middle index will going to be larger and can be used to make rightSubTree of the BST

    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    // Write your code here
    return helper(input, 0, n - 1);
}
// ======================================
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

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    BinaryTreeNode<int> *root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}