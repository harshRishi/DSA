#include <iostream>
#include <vector>
#include <queue>
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

void printLevelWise(TreeNode<int> *root)
{
    // Write your code here
    queue<TreeNode<int> *> pendingNodes; // making our queue to store the data of the treeNode
    pendingNodes.push(root);             // for the first iteration we're filling up the queue

    while (!pendingNodes.empty()) // run loop untill queue is empty
    {
        TreeNode<int> *front = pendingNodes.front(); // taking out front of the queue
        pendingNodes.pop();                          // And than popping it out of the queue

        int numChild = front->children.size(); // getting the total number of children of the current parent so that we can iterate that many times
        cout << front->data << ":";
        
        for (int i = 0; i < numChild; i++)
        {
            if (i == (numChild - 1))
            {
                cout << front->children[i]->data;
            }
            else
            {
                cout << front->children[i]->data << ",";
            }
            pendingNodes.push(front->children[i]); // filling up the new childrens
        }
        cout << endl;
    }
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
    printLevelWise(root);
    delete root; // here we're calling the destrutor which will call ~TreeNode()
}