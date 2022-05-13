#include <iostream>
#include <queue>
#include <vector>
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

void getNextLargerElementUtil(TreeNode<int> *root, int x, TreeNode<int> **ans)
{
    if (root->data > x)
    { // Here we know that temp and ans both are greater than x so we'll going to need the smaller value out of both bcoz that will goin to be more closer to x
        if (!(*ans) || (*ans)->data > root->data)
        {
            (*ans) = root;
        }
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        getNextLargerElementUtil(root->children[i], x, ans); // this will come up with a TreeNode greater than that of x in that child branch
    }
}

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    // Write your code here
    if (root == NULL) // this is edge case
    {
        return root;
    }

    TreeNode<int> *ans = NULL;
    getNextLargerElementUtil(root, x, &ans);

    return ans;
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
    int x;
    cin >> x;
    TreeNode<int> *ans = getNextLargerElement(root, x);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}