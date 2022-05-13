#include <iostream>
#include <queue>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

// ----------------------- DRY RUN -----------------------------------??

pair<Node<int> *, Node<int> *> helper(BinaryTreeNode<int> *root)
{
    // Base Case
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> ans;
        ans.first = NULL;  // head
        ans.second = NULL; // tail
        return ans;
    }

    pair<Node<int> *, Node<int> *> leftLL = helper(root->left);
    pair<Node<int> *, Node<int> *> rightLL = helper(root->right);

    Node<int> *newNode = new Node<int>(root->data); // created a Link Node with root data

    if (leftLL.second != NULL) // if left ll tail is not NULL than we should point tial to the newNode
    {
        leftLL.second->next = newNode; // connect tail of left to the newNode(i.e root node)
    }
    newNode->next = rightLL.first; // connect the newNode(i.e root node) to the right ll

    pair<Node<int> *, Node<int> *> ans;

    if (leftLL.first != NULL) // this means left ll is there and we need to return that in ans's first i.e head of ans, else we'll put newNode to final ans's head
        ans.first = leftLL.first;
    else
        ans.first = newNode;

    if (rightLL.second != NULL) // tail of right ll be tail of our final tail else if rightsuBTree is NULL make newNode as tail of the final ans
        ans.second = rightLL.second;
    else
        ans.second = newNode;
    return ans;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    // Write your code here
    return helper(root).first;
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
    Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}