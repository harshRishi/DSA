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

/* /////=======================================Time Complexcity O(n * height) ================================ ??
int height(BinaryTreeNode<int> *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0; // this means root is NULL and height of NULL is zero
    }

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return true; // this means: a tree without node is always balanced so we returned true
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if (abs(lHeight - rHeight) > 1)
    {
        return false;
    }
    else
    {
        bool lChild = isBalanced(root->left);
        bool rChild = isBalanced(root->rigth);
    }
}
*/

/* ============================= Time Complexcity O(n) +============== ??
The Idea here is that we're compairing the height of left and right subTree
if the absolute diff bw both heights are greater than 1 than thr whole tree isn't balanced and we'll store false in our pair class object ans
and also if one of the child (i.e right and left) in recusive ans return false in the pair class object ans.second than also return store false in our main ans
?? only if above both conditions are satisfied thn only store true in the final ans.. 
*/
pair<int, bool> helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> ans;
        ans.first = 0;     // height
        ans.second = true; // check
        return ans;
    }

    pair<int, bool> leftAns = helper(root->left);
    pair<int, bool> rightAns = helper(root->right);

    pair<int, bool> ans;
    ans.first = 1 + max(leftAns.first, rightAns.first);
    // if height diff bw both the children are more than 1 return false || OR || leftAns ya RightAns mein se ek Ka bool false ho toh return false
    if (abs(leftAns.first - rightAns.first) > 1 || (!leftAns.second) || (!rightAns.second))
    {
        ans.second = false;
    }
    else
    {
        ans.second = true;
    }
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    return helper(root).second;
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
    cout << (isBalanced(root) ? "true" : "false");
}