#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

void helper(TreeNode<int> *root, TreeNode<int> **first, TreeNode<int> **second)
{
    if (*first == NULL)
    {
        *first = root;
    }
    else if (root->data >= (*first)->data)
    { // tansfer the current max to the 2nd max as root is now going to be the first max
        *second = *first;
        *first = root;
    }
    else if (root->data < (*first)->data && (*second) == NULL)
    {
        *second = root;
    }
    else if (root->data > (*second)->data && root->data < (*first)->data) // this means root lie in bw first and second
    {                                                                     // move second to the root
        *second = root;
    }

    for (int i = 0; i < root->children.size(); i++) // this is our recusive call
    {
        helper(root->children[i], first, second);
    }
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{

    if (root == NULL) // Edge Case
    {
        return NULL;
    }

    TreeNode<int> *first = NULL;
    TreeNode<int> *second = NULL;

    helper(root, &first, &second);

    if (second == NULL || second->data == first->data)
    {
        return NULL;
    }
    return second;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}