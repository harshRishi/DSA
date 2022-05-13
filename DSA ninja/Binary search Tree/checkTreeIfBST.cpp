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
 // ============ Solution 1 ============//
#include <climits>
class triple
{
public:
    bool check;
    int minimum;
    int maximum;
};

triple isBST_better(BinaryTreeNode<int> *root)
{
    // Base Case
    if (root == NULL)
    {
        triple ans;
        ans.check = true;
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        return ans;
    }

    triple leftSubTree = isBST_better(root->left);
    triple rightSubTree = isBST_better(root->right);

    int FinalMin = min(root->data, min(leftSubTree.minimum, rightSubTree.minimum));                                                              // compare everything with root's data so to find min
    int FinalMax = max(root->data, max(leftSubTree.maximum, rightSubTree.maximum));                                                              // compare everything with root's data so to find max
    bool finalCheck = (root->data > leftSubTree.maximum) && (root->data <= rightSubTree.minimum) && (leftSubTree.check) && (rightSubTree.check); // here we're compring root data from left to be greater than and root data to be less or equal to right's minimium

    triple ans;
    ans.check = finalCheck;
    ans.minimum = FinalMin;
    ans.maximum = FinalMax;
    return ans;
}

bool isBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    return isBST_better(root).check;
}

// ================== here Time complexcity is same as that of isBST_better but here we reduced the number of variables ====== // BEST SOLUTION
bool isBST2(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    // Base Case
    if (root == NULL)
        return true;

    // if root is out the range than return false
    if (root->data > max || root->data < min)
        return false;

    bool leftAns = isBST2(root->left, min, root->data - 1); // as left side contain smaller data than root so we reduced the upper boundary
    bool rightAns = isBST2(root->right, root->data, max);   // as right subTree contains larger or equal data than root, so we increased the min to root's data

    return leftAns && rightAns; // if both are true than only return true else false
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
    cout << (isBST(root) ? "true" : "false");
}