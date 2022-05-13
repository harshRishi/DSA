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

template <typename T>
class Pair // here we made this pair call so that we can get sum of childs and parent Node in single go.
{
public:
    T xSum;
    TreeNode<T> *xNode;
};

Pair<int> helper(TreeNode<int> *root) // we've used this helper so that we can return Pair class object
{
    if (root == NULL) // this is just an edge case where root is null
    {
        Pair<int> ans;
        ans.xSum = 0;
        ans.xNode = root;
    }

    // this is our small Calc
    Pair<int> maxAns; // here we've made Pair Class object maxAnd which will store sum of childs and it's parent TreeNode
    maxAns.xSum = root->data;
    maxAns.xNode = new TreeNode<int>(root->data);
    for (int i = 0; i < root->children.size(); i++) // calc for the current root Child Sum
    {
        maxAns.xSum += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++) // This Loop is for Child and will going to work our Recursion
    {
        Pair<int> childAns; // here we've created a childAns class Which will store child's xSum and its own TreeNode; Through Recursion
        childAns = helper(root->children[i]);

        if (childAns.xSum > maxAns.xSum) // here we've compared childAns with our Current MaxAns
        {
            maxAns.xSum = childAns.xSum;
            maxAns.xNode = childAns.xNode;
        }
    }
    return maxAns;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // Write your code here
    Pair<int> ans = helper(root);
    return ans.xNode;
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

    TreeNode<int> *ans = maxSumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}